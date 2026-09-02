// Copyright (c) 2026 Tom Iwan
// PERMISSION IS HEREBY GARANTED TO ANYONE TO DO ANYTHING WITH THIS SHIT EXEPT FOR THE USE IN PROJECTS ACCUMULATING CAPITAL
// THIS SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.

#pragma once

#include <cstdint>
#include <cstdio>
#include <string>
#include <format>
#include <unordered_map>

namespace Escapes
{
    //colors
	enum Color {
		BLACK,
		RED,
		GREEN,
		YELLOW,
		BLUE,
		MAGENTA,
		CYAN,
		WHITE
	};

	const std::unordered_map<Color, int> COLOR_MAP = {
		{BLACK,   0},
		{RED,     1},
		{GREEN,   2},
		{YELLOW,  3},
		{BLUE,    4},
		{MAGENTA, 5},
		{CYAN,    6},
		{WHITE,   7}
	};

	const int COLOR_OFFSET = 30;

	const int COLOR_OFFSET_BASE = 40;
	const int UNSATTURATED_OFFSET = 60;

    struct ColorRGB
    {
        uint8_t r, g, b;
    };

    inline ColorRGB RGB(uint8_t r, uint8_t g, uint8_t b) //there because f not in namespace, no brace initialization
    {
        return {r, g, b};
    }

	inline std::string ColoredText(const std::string &s, Color c)
	{
		return std::format("\x1B[{}m{}\033[0m", COLOR_OFFSET + COLOR_MAP.at(c), s);
	}

	inline std::string ColoredTextLight(const std::string &s, Color c)
	{
		return std::format("\x1B[{}m{}\033[0m", COLOR_OFFSET + UNSATTURATED_OFFSET + COLOR_MAP.at(c), s);
	}

    inline std::string ColoredTextRGB(const std::string &s, ColorRGB c)
    {
        return std::format("\x1B[38;2;{};{};{}m{}\x1B[0m", c.r, c.g, c.b, s);
    }

    inline std::string ColoredBase(const std::string &s, Color c)
    {
        return std::format("\x1B[{}m{}\033[0m", COLOR_OFFSET_BASE + COLOR_MAP.at(c), s);
    }

    inline std::string ColoredBaseLight(const std::string &s, Color c)
    {
		return std::format("\033[3;{};30m{}\033[0m", COLOR_OFFSET_BASE + UNSATTURATED_OFFSET+ COLOR_MAP.at(c), s);
    }

    inline std::string ColoredBaseRGB(const std::string &s, ColorRGB c)
    {
        return std::format("\x1B[48;2;{};{};{}m{}\x1B[0m", c.r, c.g, c.b, s);
    }

    inline void BeginColor(Color c)
    {
        std::printf("\x1b[%um", COLOR_OFFSET + COLOR_MAP.at(c));
    }

    inline void EndColor()
    {
        std::printf("\033[0m");
    }

    inline void BeginColorLight(Color c)
    {
        std::printf("\x1b[%um", UNSATTURATED_OFFSET + COLOR_MAP.at(c));
    }

    inline void BeginColorBase(Color c)
    {
        std::printf("\x1b[%um", COLOR_OFFSET_BASE + COLOR_MAP.at(c));
    }

    inline void BeginColorLightBase(Color c)
    {
        std::printf("\x1b[%um", COLOR_OFFSET + UNSATTURATED_OFFSET + COLOR_MAP.at(c));
    }

    inline void BeginColorRGB(ColorRGB c)
    {
        std::printf("\x1B[38;2;%u;%u;%um", c.r, c.g, c.b);
    }

    inline void BeginColorBaseRGB(ColorRGB c)
    {
        std::printf("\x1B[48;2;%u;%u;%um", c.r, c.g, c.b);
    }

    //styles
    enum Style
    {
        BOLD,
        DIM,
        ITALIC,
        UNDERLINE,
        BLINKING,
        INVERSE,
        HIDDEN,
        STRIKETHROUGH
    };

    inline void ResetStyles()
    {
        std::printf("\x1b[0m");
    }

    const std::unordered_map<Style, int> STYLE_MAP = {
        {BOLD, 1},
        {DIM, 2},
        {ITALIC, 3},
        {UNDERLINE, 4},
        {BLINKING, 5},
        {INVERSE, 7},
        {HIDDEN, 8},\
        {STRIKETHROUGH, 9}
    };

    inline void SetStyle(Style s)
    {
        std::printf("\x1b[%um", STYLE_MAP.at(s));
    }

    //erase
    inline void ClearLine()
    {
        std::printf("\x1b[2K");
    }

    inline void ClearDisplay()
    {
        std::printf("\x1b[3J");
    }

    inline void ClearDisplayCursorToEnd()
    {
        std::printf("\x1b[0J");
    }

    inline void ClearDisplayCursorToBegin()
    {
        std::printf("\x1b[1J");
    }

    //Cursor
    inline void BeginPrevLine()
    {
        std::printf("\x1b[1F");
    }

    inline void CursorPos(uint32_t line, uint32_t column)
    {
        std::printf("\x1b[%u;%uH", line, column);
    }

    enum Direction
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    const std::unordered_map<Direction, char> DIRECTION_MAP
    {
        {UP, 'A'},
        {DOWN, 'B'},
        {LEFT, 'D'},
        {RIGHT, 'C'}
    };

    inline void MoveCursorDir(Direction dir, uint32_t n = 1)
    {
        std::printf("\x1b[%u%c", n, DIRECTION_MAP.at(dir));
    }
}
