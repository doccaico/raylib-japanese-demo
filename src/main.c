#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"

static char *title = "吾輩は猫である";

static char *creator = "夏目漱石";

static char *writing =
    "どこで生れたかとんと見当けんとうがつかぬ。\n"
    "何でも薄暗いじめじめした所でニャーニャー泣いていた事だけは記憶している。\n"
    "吾輩はここで始めて人間というものを見た。しかもあとで聞くとそれは書生という人間中で\n"
    "一番獰悪な種族であったそうだ。\n"
    "この書生というのは時々我々を捕えて煮て食うという話である。\n"
    "しかしその当時は何という考もなかったから別段恐しいとも思わなかった。\n"
    "ただ彼の掌に載せられてスーと持ち上げられた時何だかフワフワした感じがあったばかりで\n"
    "ある。掌の上で少し落ちついて書生の顔を見たのがいわゆる人間というものの見始であろう\n"
    "。この時妙なものだと思った感じが今でも残っている。第一毛をもって装飾されべきはずの\n"
    "顔がつるつるしてまるで薬缶だ。\n"
    ;

void die(const char *fmt, ...)
{
    char msg[256];
    va_list ap;
    va_start(ap, fmt);
    vsprintf(msg, fmt, ap);
    va_end(ap);
    exit(EXIT_FAILURE);
}

char *read_file(const char *filename)
{
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        die("Failed to open file '%s'\n", filename);
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);

    if (size == -1) {
        die("Failed to getting file size with ftell\n");
    }

    fseek(file, 0, SEEK_SET);

    char *font_data = malloc(size);
    if (font_data == NULL) {
        fclose(file);
        die("Failed to allocate memory with malloc\n");
    }

    if (fgets(font_data, (int)size, file) == NULL) {
        free(font_data);
        fclose(file);
        die("Failed to fgets\n");
    }

    return font_data;
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "I Am a Cat");

    SetTargetFPS(30);

    char *text_data = read_file("resources/font.bin");

    int codepointsCount;
    int *codepoints = LoadCodepoints(text_data, &codepointsCount);

    Font font = LoadFontEx("resources/MPLUS1p-Bold.ttf", 32, codepoints, codepointsCount);

    SetTextureFilter(font.texture, TEXTURE_FILTER_BILINEAR);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTextEx(font, writing, (Vector2){10, 10}, 24.0, 2.5, BLACK);
            DrawTextEx(font, title, (Vector2){400+160, 222+100}, 28.0, 2.5, BLACK);
            DrawTextEx(font, creator, (Vector2){400+225, 222+150}, 28.0, 2.5, BLACK);
        EndDrawing();
    }

    UnloadFont(font);
    UnloadCodepoints(codepoints);
    free(text_data);

    CloseWindow();

    return 0;
}
