/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:29:39 by asafrono          #+#    #+#             */
/*   Updated: 2024/11/05 11:39:34 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>  // Include for va_list and related macros
# include <unistd.h>  // Include for write function
# include <stdio.h>

// Function prototypes for utility functions
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_putnbr_base(unsigned long long n, char *base);

// Function prototype for the main printf function
int	ft_printf(const char *format, ...);

// // Function prototypes for format handling (if you want to expose them)
int	handle_char(va_list args);
int	handle_string(va_list args);
int	handle_pointer(va_list args);
int	handle_int(va_list args);
int	handle_unsigned(va_list args);
int	handle_hex_lower(va_list args);
int	handle_hex_upper(va_list args);
int	handle_percent(void);
int	handle_format(char specifier, va_list args);

#endif
