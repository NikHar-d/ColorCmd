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
 * -----------------------------------------------------------------
 *                         Build command:
 * For g++:
 * +-- g++ main.cpp -o out.exe -LC:/PathTo/LibFolder -lColorCmd
 * For CMake:
 *
 ******************************************************************/


/* Allow console coloring for Windows
 * Uses windows.h for enabling console colors through text commands
 */
void ColorEnable();

/* Sets the color of text
 */
void ColorFront(int r, int g, int b);

/* Sets color of background for character
 */
void ColorBack(int r, int g, int b);

/* Resets colors to original console colors
 */
void ColorReset();
