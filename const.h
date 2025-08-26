#ifndef ROOTS_H
#define ROOTS_H

//#include <TXLib.h>

//! Константы цветов шрифта для вывода
//! 
//! @par Цвета:
//! - RED
//! - RESET
//!

#define COLORS

#define RED "\x1b[31m" 
#define RESET "\x1b[0m"
#define GREEN "\x1b[32m"
#define CYAN "\x1b[36m"
#define BLUE "\x1b[34m"
    
#define WHITEBG "\x1b[47m"

//! @}

//! Количество выводимых корней

enum ROOTS {ZERO_ROOTS = 0, ONE_ROOT = 1, TWO_ROOTS = 2};
//!
#define ERRATE 1e-12//!< Погрешность
#define ERR -1//!< Уравнению удовлетворяют все действительные числа

#endif