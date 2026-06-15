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
 *    function [ColorEnable();]
 *
 * 2. Set the color of text and/or the background color with
 *    corresponding functions, passing 3 int values from 0 to 255
 *    for red, green and blue channel [ColorBack(180,0,65);]
 *    [ColorFront(255,255,0);]
 *
 * 3. Print the information, that must be colored
 *    [std::cout << "some colored information"]
 *
 * 4. Reset output back to normal. If wouldn't do so, the output
 *    of the console will continue to be colored with last sets
 *    of colors. [ColorReset();]
 *
 ******************************************************************/

#define CCMD_FORE 0
#define CCMD_BACK 1

namespace ColorCmd{
    /* Allow console coloring for Windows
     * Uses windows.h for enabling console colors through text commands
     */
    void Init();

    /* Sets the color of text
     */
    void Fore(int r, int g, int b);
    void Fore(int rgb);

    /* Sets color of background for character
     */
    void Back(int r, int g, int b);
    void Back(int rgb);
    
    /* Printf with color in one line
     */
    void Printf(int rgb, const char* format, ...);
    void Printf(int r, int g, int b, const char* format, ...);
    void Printf(int type, int rgb, const char* format, ...);
    void Printf(int type, int r, int g, int b, const char* format, ...);
    void PrintfBoth(int FORErgb, int BACKrgb, const char* format, ...);
    void PrintfBoth(int FOREr, int FOREg, int FOREb, int BACKr, int BACKg, int BACKb, const char* format, ...);

    void Warn(const char* format, ...);
    void Err(const char* format, ...);
    void Good(const char* format, ...);
    /* Resets colors to original console colors
     */
    void Reset();
}
