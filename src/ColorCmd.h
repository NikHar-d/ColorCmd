/*******************************************************************
 * ColorCmd v1.0
 * Colored windows console characters and background for c++
 *------------------------------------------------------------------
 * 
 * 
 * This is free and unencumbered software released into the public domain.
 * 
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 * 
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 * 
 * For more information, please refer to <https://unlicense.org>
 *
 *------------------------------------------------------------------
 *
 *                           How to use:
 * 1. Initialize the windows console colors, using the ColorEnable
 *    function [ColorCmd::ColorInit();]
 *
 * 2. Set the color of text and/or the background color with
 *    corresponding functions, passing 3 int values from 0 to 255
 *    for red, green and blue channel [ColorBack(180,0,65);]
 *    [ColorCmd::Fore(255,255,0);]
 *
 * 3. Print the information, that must be colored
 *    [std::cout << "some colored information"]
 *
 * 4. Reset output back to normal. If wouldn't do so, the output
 *    of the console will continue to be colored with last sets
 *    of colors. [ColorCmd::ColorReset();]
 *
 *
 *                       Or else with Prinf
 * 1. Initialize the windows console colors, using the ColorEnable
 *    function [ColorCmd::ColorInit();]
 *
 * 2. Use Printf and pass the color in format of single integer or
 *    three integers, after that, pass the text like in std::prinf
 *    and values after
 *    [ColorCmd::Printf(0xff00ff, "%d: magenta text", 1)]
 *    [ColorCmd::Printf(255, 0, 255, "%d: magenta text", 1)]
 *
 * 4. Reset output back to normal. If wouldn't do so, the output
 *    of the console will continue to be colored with last sets
 *    of colors. [ColorCmd::ColorReset();]
 *
 ******************************************************************/

#define CCMD_FORE 0
#define CCMD_BACK 1

namespace ColorCmd{
    /* Allow console coloring for Windows
     * Uses windows.h for enabling console colors through text commands
     */
    void Init();

    // Sets the color of text
    void Fore(int r, int g, int b);
    void Fore(int rgb);

    // Sets color of background for characters
    void Back(int r, int g, int b);
    void Back(int rgb);
    
    // Resets colors to original console colors
    void Reset();
    
    // Printf for coloring in one line
    // single integer value e.g. 0xffaa6c or 16755308
    void Printf(int rgb, const char* format, ...);
    // three integer inputs for red, green and blue e.g. (255,255,0)
    void Printf(int r, int g, int b, const char* format, ...);
    // allows to pass the type of coloring: background (CCMD_BACK) or foreground (CCMD_FORE)
    void Printf(int type, int rgb, const char* format, ...);
    // allows to pass the type of coloring: background (CCMD_BACK) or foreground (CCMD_FORE) (split rgb inputs)
    void Printf(int type, int r, int g, int b, const char* format, ...);
    // colors both background and foreground by passing fore color and back color at once
    void PrintfBoth(int FORErgb, int BACKrgb, const char* format, ...);
    // colors both background and foreground by passing fore color and back color at once (split rgb inputs)
    void PrintfBoth(int FOREr, int FOREg, int FOREb, int BACKr, int BACKg, int BACKb, const char* format, ...);

    // preset for yellow color and slightly yellow background, newline at the end and color auto reset
    void Warn(const char* format, ...);
    // preset for white text on red background, newline at the end and color auto reset
    void Err(const char* format, ...);
    // preset for green text, newline at the end and color auto reset
    void Good(const char* format, ...);
}
