/*
 * 
 *                           /$$                                     /$$                        /$$   /$$                      /$$$           /$$   /$$$
 *                          | $$                                    | $$                       |__/  | $$                     /$$_/         /$$$$  |_  $$
 *      /$$$$$$  /$$   /$$ /$$$$$$   /$$   /$$  /$$$$$$   /$$$$$$  /$$$$$$    /$$$$$$  /$$$$$$  /$$ /$$$$$$   /$$$$$$$       /$$//$$    /$$|_  $$    \  $$
 *     /$$__  $$|  $$ /$$/|_  $$_/  | $$  | $$ /$$__  $$ /$$__  $$|_  $$_/   /$$__  $$|____  $$| $$|_  $$_/  /$$_____/      | $$|  $$  /$$/  | $$     | $$
 *    | $$$$$$$$ \  $$$$/   | $$    | $$  | $$| $$  \ $$| $$$$$$$$  | $$    | $$  \__/ /$$$$$$$| $$  | $$   |  $$$$$$       | $$ \  $$/$$/   | $$     | $$
 *    | $$_____/  >$$  $$   | $$ /$$| $$  | $$| $$  | $$| $$_____/  | $$ /$$| $$      /$$__  $$| $$  | $$ /$$\____  $$      |  $$ \  $$$/    | $$     /$$/
 *    |  $$$$$$$ /$$/\  $$  |  $$$$/|  $$$$$$$| $$$$$$$/|  $$$$$$$  |  $$$$/| $$     |  $$$$$$$| $$  |  $$$$//$$$$$$$/       \  $$$\  $/    /$$$$$$ /$$$/
 *     \_______/|__/  \__/   \___/   \____  $$| $$____/  \_______/   \___/  |__/      \_______/|__/   \___/ |_______/         \___/ \_/    |______/|___/
 *                                   /$$  | $$| $$
 *                                  |  $$$$$$/| $$
 *                                   \______/ |__/
 * 
 */

/**
 * @file extypetraits1.hpp
 * @brief Provides basic and extended C++ typetraits and metaprogramming utilities.
 * @author wandrewaustin
 */

/*
 * Copyright (c) 2026 wandrewaustin
 * SPDX-License-Identifier: MIT
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE 
 * SOFTWARE.
 */

#ifndef _EXTYPETRAITS_VERSION
#define _EXTYPETRAITS_VERSION 1

/*
 *         _                _             _      _     _          _   _
 *      __| |_ __ _ _ _  __| |__ _ _ _ __| |  __| |___| |_ ___ __| |_(_)___ _ _
 *     (_-<  _/ _` | ' \/ _` / _` | '_/ _` | / _` / -_)  _/ -_) _|  _| / _ \ ' \
 *     /__/\__\__,_|_||_\__,_\__,_|_| \__,_| \__,_\___|\__\___\__|\__|_\___/_||_|
 *
 */

#if defined(_MSVC_LANG)
#   define _EXTYPETRAITS_HAS_CXX11 (_MSVC_LANG >= 201103) ? 1 : 0
#   define _EXTYPETRAITS_HAS_CXX14 (_MSVC_LANG >= 201402) ? 1 : 0
#   define _EXTYPETRAITS_HAS_CXX17 (_MSVC_LANG >= 201703) ? 1 : 0
#   define _EXTYPETRAITS_HAS_CXX20 (_MSVC_LANG >= 202002) ? 1 : 0
#else
#   define _EXTYPETRAITS_HAS_CXX11 (__cplusplus >= 201103) ? 1 : 0
#   define _EXTYPETRAITS_HAS_CXX14 (__cplusplus >= 201402) ? 1 : 0
#   define _EXTYPETRAITS_HAS_CXX17 (__cplusplus >= 201703) ? 1 : 0
#   define _EXTYPETRAITS_HAS_CXX20 (__cplusplus >= 202002) ? 1 : 0
#endif

#if !_EXTYPETRAITS_HAS_CXX11
#   error "extypetraits1 requires a minimum of C++11."
#endif

/*
 *                        _ _              _     _          _   _
 *      __ ___ _ __  _ __(_) |___ _ _   __| |___| |_ ___ __| |_(_)___ _ _
 *     / _/ _ \ '  \| '_ \ | / -_) '_| / _` / -_)  _/ -_) _|  _| / _ \ ' \
 *     \__\___/_|_|_| .__/_|_\___|_|   \__,_\___|\__\___\__|\__|_\___/_||_|
 *                  |_|
 */

#if defined(__INTEL_COMPILER)
#	define _EXTYPETRAITS_INTEL_COMPILER 1
#else
#	define _EXTYPETRAITS_INTEL_COMPILER 0
#endif

#if defined(__clang__)
#	define _EXTYPETRAITS_CLANG 1
#else
#	define _EXTYPETRAITS_CLANG 0
#endif

#if defined(__GNUC__) || defined(__GNUG__)
#	define _EXTYPETRAITS_GNUC 1
#else
#	define _EXTYPETRAITS_GNUC 0
#endif

#if defined(_MSC_VER)
#	define _EXTYPETRAITS_MSVC 1
#else
#	define _EXTYPETRAITS_MSVC 0
#endif

#if (!_EXTYPETRAITS_CLANG && !_EXTYPETRAITS_GNUC && !_EXTYPETRAITS_MSVC) || _EXTYPETRAITS_INTEL_COMPILER
#	error "extypetraits1 only supports MSVC/GNUC/Clang."
#endif 


/*
 *         _                _             _      _                       _         _                                _      __ _      _ _   _
 *      __| |_ __ _ _ _  __| |__ _ _ _ __| |  __| |___ _ __  ___ _ _  __| |___ _ _| |_   _ __  __ _ __ _ _ ___   __| |___ / _(_)_ _ (_) |_(_)___ _ _  ___
 *     (_-<  _/ _` | ' \/ _` / _` | '_/ _` | / _` / -_) '_ \/ -_) ' \/ _` / -_) ' \  _| | '  \/ _` / _| '_/ _ \ / _` / -_)  _| | ' \| |  _| / _ \ ' \(_-<
 *     /__/\__\__,_|_||_\__,_\__,_|_| \__,_| \__,_\___| .__/\___|_||_\__,_\___|_||_\__| |_|_|_\__,_\__|_| \___/ \__,_\___|_| |_|_||_|_|\__|_\___/_||_/__/
 *                                                    |_|
 */

#if _EXTYPETRAITS_HAS_CXX17
#   define _EXTYPETRAITS_NODISCARD [[nodiscard]]
#   define _EXTYPETRAITS_INLINE17 inline
#else
#   define _EXTYPETRAITS_NODISCARD
#   define _EXTYPETRAITS_INLINE17
#endif

/*
 *                                                 _              _           _
 *      _ _  __ _ _ __  ___ ____ __  __ _ __ ___  | |__  ___ __ _(_)_ _  _ _ (_)_ _  __ _
 *     | ' \/ _` | '  \/ -_|_-< '_ \/ _` / _/ -_) | '_ \/ -_) _` | | ' \| ' \| | ' \/ _` |
 *     |_||_\__,_|_|_|_\___/__/ .__/\__,_\__\___| |_.__/\___\__, |_|_||_|_||_|_|_||_\__, |
 *                            |_|                           |___/                   |___/
 */

#if defined(EXTYPETRAITS_NAMESPACE)
	namespace EXTYPETRAITS_NAMESPACE {
#else
	namespace extt {
#endif

/*
 *      _    _         _   _ _
 *     (_)__| |___ _ _| |_(_) |_ _  _
 *     | / _` / -_) ' \  _| |  _| || |
 *     |_\__,_\___|_||_\__|_|\__|\_, |
 *                               |__/
 */

template <typename _Type>
struct identity { using type = _Type; };

template <typename _Type>
using identity_t = identity<_Type>::type;

/*
 *              _    _  _
 *     __ _____(_)__| || |_
 *     \ V / _ \ / _` ||  _|
 *      \_/\___/_\__,_|_\__|
 *                   |___|
 */

template <typename... _Types>
using void_t = void;

/*
 *                     _            _
 *      __ ___ _ _  __| |_ __ _ _ _| |_
 *     / _/ _ \ ' \(_-<  _/ _` | ' \  _|
 *     \__\___/_||_/__/\__\__,_|_||_\__|
 *
 */

template <typename _Type, _Type _Value>
struct constant {
	using type = constant;

	using value_type = _Type;
	static constexpr value_type value = _Value;

	constexpr operator value_type() const noexcept { return value; }
	_EXTYPETRAITS_NODISCARD constexpr value_type operator()() const noexcept { return value; }
};

/*
 *      _              _                                _            _
 *     | |__  ___  ___| |___ __ _ _ _    __ ___ _ _  __| |_ __ _ _ _| |_
 *     | '_ \/ _ \/ _ \ / -_) _` | ' \  / _/ _ \ ' \(_-<  _/ _` | ' \  _|
 *     |_.__/\___/\___/_\___\__,_|_||_|_\__\___/_||_/__/\__\__,_|_||_\__|
 *                                   |___|
 */

template <bool _Value>
using boolean_constant = constant<bool, _Value>;

using true_t = boolean_constant<true>;
using false_t = boolean_constant<false>;

/*
 *                    _    _       _  __
 *      ___ _ _  __ _| |__| |___  (_)/ _|
 *     / -_) ' \/ _` | '_ \ / -_) | |  _|
 *     \___|_||_\__,_|_.__/_\___|_|_|_|
 *                             |___|
 */

template <bool _Test, typename _Type = void>
struct enable_if {};

template <typename _Type>
struct enable_if<true, _Type> : identity<_Type> {};

template <bool _Test, typename _Type = void>
using enable_if_t = typename enable_if<_Test, _Type>::type;

/*
 *         _ _          _    _       _  __
 *      __| (_)___ __ _| |__| |___  (_)/ _|
 *     / _` | (_-</ _` | '_ \ / -_) | |  _|
 *     \__,_|_/__/\__,_|_.__/_\___|_|_|_|
 *                               |___|
 */

template <bool _Test, typename _Type = void>
struct disable_if {};

template <typename _Type>
struct disable_if<false, _Type> : identity<_Type> {};

template <bool _Test, typename _Type = void>
using disable_if_t = typename disable_if<_Test, _Type>::type;

/*
 *                                                 _   
 *      _ _ ___ _ __  _____ _____   __ ___ _ _  __| |_ 
 *     | '_/ -_) '  \/ _ \ V / -_) / _/ _ \ ' \(_-<  _|
 *     |_| \___|_|_|_\___/\_/\___|_\__\___/_||_/__/\__|
 *                              |___|                  
 */

template <typename _Type>
struct remove_const : identity<_Type> {};

template <typename _Type>
struct remove_const<const _Type> : identity<_Type> {};

template <typename _Type>
using remove_const_t = typename remove_const<_Type>::type;

/*
 *                                         _      _   _ _
 *      _ _ ___ _ __  _____ _____ __ _____| |__ _| |_(_) |___
 *     | '_/ -_) '  \/ _ \ V / -_)\ V / _ \ / _` |  _| | / -_)
 *     |_| \___|_|_|_\___/\_/\___|_\_/\___/_\__,_|\__|_|_\___|
 *                              |___|
 */

template <typename _Type>
struct remove_volatile : identity<_Type> {};

template <typename _Type>
struct remove_volatile<volatile _Type> : identity<_Type> {};

template <typename _Type>
using remove_volatile_t = typename remove_volatile<_Type>::type;

/*
 *                                                 _            _      _   _ _
 *      _ _ ___ _ __  _____ _____   __ ___ _ _  __| |_ __ _____| |__ _| |_(_) |___
 *     | '_/ -_) '  \/ _ \ V / -_) / _/ _ \ ' \(_-<  _|\ V / _ \ / _` |  _| | / -_)
 *     |_| \___|_|_|_\___/\_/\___|_\__\___/_||_/__/\__|_\_/\___/_\__,_|\__|_|_\___|
 *                              |___|                |___|
 */

template <typename _Type>
struct remove_const_volatile : remove_volatile<remove_const_t<_Type>> {};

template <typename _Type>
using remove_const_volatile_t = typename remove_const_volatile<_Type>::type;

/*
 *                                           __                         
 *      _ _ ___ _ __  _____ _____   _ _ ___ / _|___ _ _ ___ _ _  __ ___ 
 *     | '_/ -_) '  \/ _ \ V / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     |_| \___|_|_|_\___/\_/\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *                              |___|                                   
 */

template <typename _Type>
struct remove_reference : identity<_Type> {};

template <typename _Type>
struct remove_reference<_Type&> : identity<_Type> {};

template <typename _Type>
struct remove_reference<_Type&&> : identity<_Type> {};

template <typename _Type>
using remove_reference_t = typename remove_reference<_Type>::type;

/*
 *                                  _          _                     __
 *      _ _ ___ _ __  _____ _____  | |_ ____ _| |_  _ ___   _ _ ___ / _|___ _ _ ___ _ _  __ ___
 *     | '_/ -_) '  \/ _ \ V / -_) | \ V / _` | | || / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     |_| \___|_|_|_\___/\_/\___|_|_|\_/\__,_|_|\_,_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *                              |___|                   |___|
 */

template <typename _Type>
struct remove_lvalue_reference : identity<_Type> {};

template <typename _Type>
struct remove_lvalue_reference<_Type&> : identity<_Type> {};

template <typename _Type>
using remove_lvalue_reference_t = typename remove_lvalue_reference<_Type>::type;

/*
 *                                                 _     _          _                     __
 *      _ _ ___ _ __  _____ _____   __ ___ _ _  __| |_  | |_ ____ _| |_  _ ___   _ _ ___ / _|___ _ _ ___ _ _  __ ___
 *     | '_/ -_) '  \/ _ \ V / -_) / _/ _ \ ' \(_-<  _| | \ V / _` | | || / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     |_| \___|_|_|_\___/\_/\___|_\__\___/_||_/__/\__|_|_|\_/\__,_|_|\_,_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *                              |___|                |___|                   |___|
 */

template <typename _Type>
struct remove_const_lvalue_reference : remove_const<remove_lvalue_reference_t<_Type>> {};

template <typename _Type>
using remove_const_lvalue_reference_t = typename remove_const_lvalue_reference<_Type>::type;

/*
 *                                         _      _   _ _       _          _                     __
 *      _ _ ___ _ __  _____ _____ __ _____| |__ _| |_(_) |___  | |_ ____ _| |_  _ ___   _ _ ___ / _|___ _ _ ___ _ _  __ ___
 *     | '_/ -_) '  \/ _ \ V / -_)\ V / _ \ / _` |  _| | / -_) | \ V / _` | | || / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     |_| \___|_|_|_\___/\_/\___|_\_/\___/_\__,_|\__|_|_\___|_|_|\_/\__,_|_|\_,_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *                              |___|                       |___|                   |___|
 */

template <typename _Type>
struct remove_volatile_lvalue_reference : remove_volatile<remove_lvalue_reference_t<_Type>> {};

template <typename _Type>
using remove_volatile_lvalue_reference_t = typename remove_volatile_lvalue_reference<_Type>::type;

/*
 *                                                 _            _      _   _ _       _          _                     __
 *      _ _ ___ _ __  _____ _____   __ ___ _ _  __| |_ __ _____| |__ _| |_(_) |___  | |_ ____ _| |_  _ ___   _ _ ___ / _|___ _ _ ___ _ _  __ ___
 *     | '_/ -_) '  \/ _ \ V / -_) / _/ _ \ ' \(_-<  _|\ V / _ \ / _` |  _| | / -_) | \ V / _` | | || / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     |_| \___|_|_|_\___/\_/\___|_\__\___/_||_/__/\__|_\_/\___/_\__,_|\__|_|_\___|_|_|\_/\__,_|_|\_,_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *                              |___|                |___|                       |___|                   |___|
 */

template <typename _Type>
struct remove_const_volatile_lvalue_reference : remove_const_volatile<remove_lvalue_reference_t<_Type>> {};

template <typename _Type>
using remove_const_volatile_lvalue_reference_t = typename remove_const_volatile_lvalue_reference<_Type>::type;

/*
 *                                               _                     __
 *      _ _ ___ _ __  _____ _____   _ ___ ____ _| |_  _ ___   _ _ ___ / _|___ _ _ ___ _ _  __ ___
 *     | '_/ -_) '  \/ _ \ V / -_) | '_\ V / _` | | || / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     |_| \___|_|_|_\___/\_/\___|_|_|  \_/\__,_|_|\_,_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *                              |___|                     |___|
 */

template <typename _Type>
struct remove_rvalue_reference : identity<_Type> {};

template <typename _Type>
struct remove_rvalue_reference<_Type&&> : identity<_Type> {};

template <typename _Type>
using remove_rvalue_reference_t = typename remove_rvalue_reference<_Type>::type;

/*
 *                                                 _                  _                     __
 *      _ _ ___ _ __  _____ _____   __ ___ _ _  __| |_   _ ___ ____ _| |_  _ ___   _ _ ___ / _|___ _ _ ___ _ _  __ ___
 *     | '_/ -_) '  \/ _ \ V / -_) / _/ _ \ ' \(_-<  _| | '_\ V / _` | | || / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     |_| \___|_|_|_\___/\_/\___|_\__\___/_||_/__/\__|_|_|  \_/\__,_|_|\_,_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *                              |___|                |___|                     |___|
 */

template <typename _Type>
struct remove_const_rvalue_reference : remove_const<remove_rvalue_reference_t<_Type>> {};

template <typename _Type>
using remove_const_rvalue_reference_t = typename remove_const_rvalue_reference<_Type>::type;

/*
 *                                         _      _   _ _                    _                     __
 *      _ _ ___ _ __  _____ _____ __ _____| |__ _| |_(_) |___   _ ___ ____ _| |_  _ ___   _ _ ___ / _|___ _ _ ___ _ _  __ ___
 *     | '_/ -_) '  \/ _ \ V / -_)\ V / _ \ / _` |  _| | / -_) | '_\ V / _` | | || / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     |_| \___|_|_|_\___/\_/\___|_\_/\___/_\__,_|\__|_|_\___|_|_|  \_/\__,_|_|\_,_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *                              |___|                       |___|                     |___|
 */

template <typename _Type>
struct remove_volatile_rvalue_reference : remove_volatile<remove_rvalue_reference_t<_Type>> {};

template <typename _Type>
using remove_volatile_rvalue_reference_t = typename remove_volatile_rvalue_reference<_Type>::type;

/*
 *                                                 _            _      _   _ _                    _                     __
 *      _ _ ___ _ __  _____ _____   __ ___ _ _  __| |_ __ _____| |__ _| |_(_) |___   _ ___ ____ _| |_  _ ___   _ _ ___ / _|___ _ _ ___ _ _  __ ___
 *     | '_/ -_) '  \/ _ \ V / -_) / _/ _ \ ' \(_-<  _|\ V / _ \ / _` |  _| | / -_) | '_\ V / _` | | || / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     |_| \___|_|_|_\___/\_/\___|_\__\___/_||_/__/\__|_\_/\___/_\__,_|\__|_|_\___|_|_|  \_/\__,_|_|\_,_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *                              |___|                |___|                       |___|                     |___|
 */

template <typename _Type>
struct remove_const_volatile_rvalue_reference : remove_const_volatile<remove_rvalue_reference_t<_Type>> {};

template <typename _Type>
using remove_const_volatile_rvalue_reference_t = typename remove_const_volatile_rvalue_reference<_Type>::type;

/*
 *                                             _     _
 *      _ _ ___ _ __  _____ _____    _ __  ___(_)_ _| |_ ___ _ _
 *     | '_/ -_) '  \/ _ \ V / -_)  | '_ \/ _ \ | ' \  _/ -_) '_|
 *     |_| \___|_|_|_\___/\_/\___|__| .__/\___/_|_||_\__\___|_|
 *                              |___|_|
 */

template <typename _Type>
struct remove_pointer : identity<_Type> {};

template <typename _Type>
struct remove_pointer<_Type*> : identity<_Type> {};

template <typename _Type>
struct remove_pointer<_Type* const> : identity<_Type> {};

template <typename _Type>
struct remove_pointer<_Type* volatile> : identity<_Type> {};

template <typename _Type>
struct remove_pointer<_Type* const volatile> : identity<_Type> {};

template <typename _Type>
using remove_pointer_t = typename remove_pointer<_Type>::type;

/*
 *                                                 _                _     _
 *      _ _ ___ _ __  _____ _____   __ ___ _ _  __| |_    _ __  ___(_)_ _| |_ ___ _ _
 *     | '_/ -_) '  \/ _ \ V / -_) / _/ _ \ ' \(_-<  _|  | '_ \/ _ \ | ' \  _/ -_) '_|
 *     |_| \___|_|_|_\___/\_/\___|_\__\___/_||_/__/\__|__| .__/\___/_|_||_\__\___|_|
 *                              |___|                |___|_|
 */

template <typename _Type>
struct remove_const_pointer : remove_const<remove_pointer_t<_Type>> {};

template <typename _Type>
using remove_const_pointer_t = typename remove_const_pointer<_Type>::type;

/*
 *                                         _      _   _ _                  _     _
 *      _ _ ___ _ __  _____ _____ __ _____| |__ _| |_(_) |___    _ __  ___(_)_ _| |_ ___ _ _
 *     | '_/ -_) '  \/ _ \ V / -_)\ V / _ \ / _` |  _| | / -_)  | '_ \/ _ \ | ' \  _/ -_) '_|
 *     |_| \___|_|_|_\___/\_/\___|_\_/\___/_\__,_|\__|_|_\___|__| .__/\___/_|_||_\__\___|_|
 *                              |___|                       |___|_|
 */

template <typename _Type>
struct remove_volatile_pointer : remove_volatile<remove_pointer_t<_Type>> {};

template <typename _Type>
using remove_volatile_pointer_t = typename remove_volatile_pointer<_Type>::type;

/*
 *                                                 _            _      _   _ _                  _     _
 *      _ _ ___ _ __  _____ _____   __ ___ _ _  __| |_ __ _____| |__ _| |_(_) |___    _ __  ___(_)_ _| |_ ___ _ _
 *     | '_/ -_) '  \/ _ \ V / -_) / _/ _ \ ' \(_-<  _|\ V / _ \ / _` |  _| | / -_)  | '_ \/ _ \ | ' \  _/ -_) '_|
 *     |_| \___|_|_|_\___/\_/\___|_\__\___/_||_/__/\__|_\_/\___/_\__,_|\__|_|_\___|__| .__/\___/_|_||_\__\___|_|
 *                              |___|                |___|                       |___|_|
 */

template <typename _Type>
struct remove_const_volatile_pointer : remove_const_volatile<remove_pointer_t<_Type>> {};

template <typename _Type>
using remove_const_volatile_pointer_t = typename remove_const_volatile_pointer<_Type>::type;

/*
 *                                          _           _
 *      _ _ ___ _ __  _____ _____   _____ _| |_ ___ _ _| |_
 *     | '_/ -_) '  \/ _ \ V / -_) / -_) \ /  _/ -_) ' \  _|
 *     |_| \___|_|_|_\___/\_/\___|_\___/_\_\\__\___|_||_\__|
 *                              |___|
 */

template <typename _Type>
struct remove_extent : identity<_Type> {};

template <typename _Type>
struct remove_extent<_Type[]> : identity<_Type> {};

template <typename _Type, unsigned _Size>
struct remove_extent<_Type[_Size]> : identity<_Type> {};

template <typename _Type>
using remove_extent_t = typename remove_extent<_Type>::type;

/*
 *              _    _                  _   
 *      __ _ __| |__| |  __ ___ _ _  __| |_ 
 *     / _` / _` / _` | / _/ _ \ ' \(_-<  _|
 *     \__,_\__,_\__,_|_\__\___/_||_/__/\__|
 *                   |___|                  
 */

template <typename _Type>
struct add_const : identity<const _Type> {};

template <typename _Type>
using add_const_t = typename add_const<_Type>::type;

/*
 *              _    _          _      _   _ _     
 *      __ _ __| |__| |__ _____| |__ _| |_(_) |___ 
 *     / _` / _` / _` |\ V / _ \ / _` |  _| | / -_)
 *     \__,_\__,_\__,_|_\_/\___/_\__,_|\__|_|_\___|
 *                   |___|                         
 */

template <typename _Type>
struct add_volatile : identity<volatile _Type> {};

template <typename _Type>
using add_volatile_t = typename add_volatile<_Type>::type;

/*
 *              _    _                  _            _      _   _ _
 *      __ _ __| |__| |  __ ___ _ _  __| |_ __ _____| |__ _| |_(_) |___
 *     / _` / _` / _` | / _/ _ \ ' \(_-<  _|\ V / _ \ / _` |  _| | / -_)
 *     \__,_\__,_\__,_|_\__\___/_||_/__/\__|_\_/\___/_\__,_|\__|_|_\___|
 *                   |___|                |___|
 */

template <typename _Type>
struct add_const_volatile : identity<const volatile _Type> {};

template <typename _Type>
using add_const_volatile_t = typename add_const_volatile<_Type>::type;

/*
 *              _    _   _          _                     __
 *      __ _ __| |__| | | |_ ____ _| |_  _ ___   _ _ ___ / _|___ _ _ ___ _ _  __ ___
 *     / _` / _` / _` | | \ V / _` | | || / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     \__,_\__,_\__,_|_|_|\_/\__,_|_|\_,_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *                   |___|                   |___|
 */

template <typename _Type, typename = void>
struct add_lvalue_reference : identity<_Type> {};

template <typename _Type>
struct add_lvalue_reference<_Type, void_t<_Type&>> : identity<_Type&> {};

template <typename _Type>
using add_lvalue_reference_t = typename add_lvalue_reference<_Type>::type;

/*
 *              _    _                  _     _          _                     __
 *      __ _ __| |__| |  __ ___ _ _  __| |_  | |_ ____ _| |_  _ ___   _ _ ___ / _|___ _ _ ___ _ _  __ ___
 *     / _` / _` / _` | / _/ _ \ ' \(_-<  _| | \ V / _` | | || / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     \__,_\__,_\__,_|_\__\___/_||_/__/\__|_|_|\_/\__,_|_|\_,_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *                   |___|                |___|                   |___|
 */

template <typename _Type>
struct add_const_lvalue_reference : add_lvalue_reference<add_const_t<_Type>> {};

template <typename _Type>
using add_const_lvalue_reference_t = typename add_const_lvalue_reference<_Type>::type;

/*
 *              _    _          _      _   _ _       _          _                     __
 *      __ _ __| |__| |__ _____| |__ _| |_(_) |___  | |_ ____ _| |_  _ ___   _ _ ___ / _|___ _ _ ___ _ _  __ ___
 *     / _` / _` / _` |\ V / _ \ / _` |  _| | / -_) | \ V / _` | | || / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     \__,_\__,_\__,_|_\_/\___/_\__,_|\__|_|_\___|_|_|\_/\__,_|_|\_,_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *                   |___|                       |___|                   |___|
 */

template <typename _Type>
struct add_volatile_lvalue_reference : add_lvalue_reference<add_volatile_t<_Type>> {};

template <typename _Type>
using add_volatile_lvalue_reference_t = typename add_volatile_lvalue_reference<_Type>::type;

/*
 *              _    _                  _            _      _   _ _       _          _                     __
 *      __ _ __| |__| |  __ ___ _ _  __| |_ __ _____| |__ _| |_(_) |___  | |_ ____ _| |_  _ ___   _ _ ___ / _|___ _ _ ___ _ _  __ ___
 *     / _` / _` / _` | / _/ _ \ ' \(_-<  _|\ V / _ \ / _` |  _| | / -_) | \ V / _` | | || / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     \__,_\__,_\__,_|_\__\___/_||_/__/\__|_\_/\___/_\__,_|\__|_|_\___|_|_|\_/\__,_|_|\_,_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *                   |___|                |___|                       |___|                   |___|
 */

template <typename _Type>
struct add_const_volatile_lvalue_reference : add_lvalue_reference<add_const_volatile_t<_Type>> {};

template <typename _Type>
using add_const_volatile_lvalue_reference_t = typename add_const_volatile_lvalue_reference<_Type>::type;

/*
 *              _    _                _                     __
 *      __ _ __| |__| |  _ ___ ____ _| |_  _ ___   _ _ ___ / _|___ _ _ ___ _ _  __ ___
 *     / _` / _` / _` | | '_\ V / _` | | || / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     \__,_\__,_\__,_|_|_|  \_/\__,_|_|\_,_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *                   |___|                     |___|
 */

template <typename _Type, typename = void>
struct add_rvalue_reference : identity<_Type> {};

template <typename _Type>
struct add_rvalue_reference<_Type, void_t<_Type&&>> : identity<_Type&&> {};

template <typename _Type>
using add_rvalue_reference_t = typename add_rvalue_reference<_Type>::type;

/*
 *              _    _                  _                  _                     __
 *      __ _ __| |__| |  __ ___ _ _  __| |_   _ ___ ____ _| |_  _ ___   _ _ ___ / _|___ _ _ ___ _ _  __ ___
 *     / _` / _` / _` | / _/ _ \ ' \(_-<  _| | '_\ V / _` | | || / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     \__,_\__,_\__,_|_\__\___/_||_/__/\__|_|_|  \_/\__,_|_|\_,_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *                   |___|                |___|                     |___|
 */

template <typename _Type>
struct add_const_rvalue_reference : add_rvalue_reference<add_const_t<_Type>> {};

template <typename _Type>
using add_const_rvalue_reference_t = typename add_const_rvalue_reference<_Type>::type;

/*
 *              _    _          _      _   _ _                    _                     __
 *      __ _ __| |__| |__ _____| |__ _| |_(_) |___   _ ___ ____ _| |_  _ ___   _ _ ___ / _|___ _ _ ___ _ _  __ ___
 *     / _` / _` / _` |\ V / _ \ / _` |  _| | / -_) | '_\ V / _` | | || / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     \__,_\__,_\__,_|_\_/\___/_\__,_|\__|_|_\___|_|_|  \_/\__,_|_|\_,_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *                   |___|                       |___|                     |___|
 */

template <typename _Type>
struct add_volatile_rvalue_reference : add_rvalue_reference<add_volatile_t<_Type>> {};

template <typename _Type>
using add_volatile_rvalue_reference_t = typename add_volatile_rvalue_reference<_Type>::type;

/*
 *              _    _                  _            _      _   _ _                    _                     __
 *      __ _ __| |__| |  __ ___ _ _  __| |_ __ _____| |__ _| |_(_) |___   _ ___ ____ _| |_  _ ___   _ _ ___ / _|___ _ _ ___ _ _  __ ___
 *     / _` / _` / _` | / _/ _ \ ' \(_-<  _|\ V / _ \ / _` |  _| | / -_) | '_\ V / _` | | || / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     \__,_\__,_\__,_|_\__\___/_||_/__/\__|_\_/\___/_\__,_|\__|_|_\___|_|_|  \_/\__,_|_|\_,_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *                   |___|                |___|                       |___|                     |___|
 */

template <typename _Type>
struct add_const_volatile_rvalue_reference : add_rvalue_reference<add_const_volatile_t<_Type>> {};

template <typename _Type>
using add_const_volatile_rvalue_reference_t = typename add_const_volatile_rvalue_reference<_Type>::type;

/*
 *              _    _              _     _
 *      __ _ __| |__| |   _ __  ___(_)_ _| |_ ___ _ _
 *     / _` / _` / _` |  | '_ \/ _ \ | ' \  _/ -_) '_|
 *     \__,_\__,_\__,_|__| .__/\___/_|_||_\__\___|_|
 *                   |___|_|
 */

template <typename _Type, typename = void>
struct add_pointer : identity<_Type> {};

template <typename _Type>
struct add_pointer<_Type, void_t<remove_reference_t<_Type>*>> : identity<_Type*> {};

template <typename _Type>
using add_pointer_t = typename add_pointer<_Type>::type;

/*
 *              _    _                  _                _     _
 *      __ _ __| |__| |  __ ___ _ _  __| |_    _ __  ___(_)_ _| |_ ___ _ _
 *     / _` / _` / _` | / _/ _ \ ' \(_-<  _|  | '_ \/ _ \ | ' \  _/ -_) '_|
 *     \__,_\__,_\__,_|_\__\___/_||_/__/\__|__| .__/\___/_|_||_\__\___|_|
 *                   |___|                |___|_|
 */

template <typename _Type>
struct add_const_pointer : add_pointer<add_const_t<_Type>> {};

template <typename _Type>
using add_const_pointer_t = typename add_const_pointer<_Type>::type;

/*
 *              _    _          _      _   _ _                  _     _
 *      __ _ __| |__| |__ _____| |__ _| |_(_) |___    _ __  ___(_)_ _| |_ ___ _ _
 *     / _` / _` / _` |\ V / _ \ / _` |  _| | / -_)  | '_ \/ _ \ | ' \  _/ -_) '_|
 *     \__,_\__,_\__,_|_\_/\___/_\__,_|\__|_|_\___|__| .__/\___/_|_||_\__\___|_|
 *                   |___|                       |___|_|
 */

template <typename _Type>
struct add_volatile_pointer : add_pointer<add_volatile_t<_Type>> {};

template <typename _Type>
using add_volatile_pointer_t = typename add_volatile_pointer<_Type>::type;

/*
 *              _    _                  _            _      _   _ _                  _     _
 *      __ _ __| |__| |  __ ___ _ _  __| |_ __ _____| |__ _| |_(_) |___    _ __  ___(_)_ _| |_ ___ _ _
 *     / _` / _` / _` | / _/ _ \ ' \(_-<  _|\ V / _ \ / _` |  _| | / -_)  | '_ \/ _ \ | ' \  _/ -_) '_|
 *     \__,_\__,_\__,_|_\__\___/_||_/__/\__|_\_/\___/_\__,_|\__|_|_\___|__| .__/\___/_|_||_\__\___|_|
 *                   |___|                |___|                       |___|_|
 */

template <typename _Type>
struct add_const_volatile_pointer : add_pointer<add_const_volatile_t<_Type>> {};

template <typename _Type>
using add_const_volatile_pointer_t = typename add_const_volatile_pointer<_Type>::type;

/*
 *              _    _           _           _
 *      __ _ __| |__| |  _____ _| |_ ___ _ _| |_
 *     / _` / _` / _` | / -_) \ /  _/ -_) ' \  _|
 *     \__,_\__,_\__,_|_\___/_\_\\__\___|_||_\__|
 *                   |___|
 */

template <typename _Type, typename = void>
struct add_extent : identity<_Type> {};

template <typename _Type>
struct add_extent<_Type, void_t<_Type[]>> : identity<_Type[]>{};

template <typename _Type>
using add_extent_t = typename add_extent<_Type>::type;

/*
 *              _    _   _                      _        _           _           _
 *      __ _ __| |__| | | |__  ___ _  _ _ _  __| |___ __| |  _____ _| |_ ___ _ _| |_
 *     / _` / _` / _` | | '_ \/ _ \ || | ' \/ _` / -_) _` | / -_) \ /  _/ -_) ' \  _|
 *     \__,_\__,_\__,_|_|_.__/\___/\_,_|_||_\__,_\___\__,_|_\___/_\_\\__\___|_||_\__|
 *                   |___|                               |___|
 */

template <typename _Type, unsigned _Size, typename = void>
struct add_bounded_extent : identity<_Type> {};

template <typename _Type, unsigned _Size>
struct add_bounded_extent<_Type, _Size, void_t<_Type[_Size]>> : identity<_Type[_Size]> {};

template <typename _Type, unsigned _Size>
using add_bounded_extent_t = typename add_bounded_extent<_Type, _Size>::type;

/*
 *      _                     _
 *     (_)___  __ ___ _ _  __| |_
 *     | (_-< / _/ _ \ ' \(_-<  _|
 *     |_/__/_\__\___/_||_/__/\__|
 *         |___|
 */

template <typename _Type>
struct is_const : false_t {};

template <typename _Type>
struct is_const<const _Type> : true_t {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_const_v = is_const<_Type>::value;
#endif

/*
 *      _             _      _   _ _
 *     (_)_____ _____| |__ _| |_(_) |___
 *     | (_-<\ V / _ \ / _` |  _| | / -_)
 *     |_/__/_\_/\___/_\__,_|\__|_|_\___|
 *         |___|
 */

template <typename _Type>
struct is_volatile : false_t {};

template <typename _Type>
struct is_volatile<volatile _Type> : true_t {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_volatile_v = is_volatile<_Type>::value;
#endif

/*
 *      _                     _            _      _   _ _
 *     (_)___  __ ___ _ _  __| |_ __ _____| |__ _| |_(_) |___
 *     | (_-< / _/ _ \ ' \(_-<  _|\ V / _ \ / _` |  _| | / -_)
 *     |_/__/_\__\___/_||_/__/\__|_\_/\___/_\__,_|\__|_|_\___|
 *         |___|                |___|
 */

template <typename _Type>
struct is_const_volatile 
	: boolean_constant<is_const<_Type>::value || is_volatile<_Type>::value> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_const_volatile_v = is_const_volatile<_Type>::value;
#endif

/*
 *      _               __                         
 *     (_)___  _ _ ___ / _|___ _ _ ___ _ _  __ ___ 
 *     | (_-< | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     |_/__/_|_| \___|_| \___|_| \___|_||_\__\___|
 *         |___|                                   
 */

template <typename _Type>
struct is_reference : false_t {};

template <typename _Type>
struct is_reference<_Type&> : true_t {};

template <typename _Type>
struct is_reference<_Type&&> : true_t {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_reference_v = is_reference<_Type>::value;
#endif

/*
 *      _                     _              __
 *     (_)___  __ ___ _ _  __| |_   _ _ ___ / _|___ _ _ ___ _ _  __ ___
 *     | (_-< / _/ _ \ ' \(_-<  _| | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     |_/__/_\__\___/_||_/__/\__|_|_| \___|_| \___|_| \___|_||_\__\___|
 *         |___|                |___|
 */

template <typename _Type>
struct is_const_reference
	: boolean_constant<is_reference<_Type>::value && is_const<remove_reference_t<_Type>>::value> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_const_reference_v = is_const_reference<_Type>::value;
#endif

/*
 *      _             _      _   _ _                __
 *     (_)_____ _____| |__ _| |_(_) |___   _ _ ___ / _|___ _ _ ___ _ _  __ ___
 *     | (_-<\ V / _ \ / _` |  _| | / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     |_/__/_\_/\___/_\__,_|\__|_|_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *         |___|                       |___|
 */

template <typename _Type>
struct is_volatile_reference
	: boolean_constant<is_reference<_Type>::value && is_volatile<remove_reference_t<_Type>>::value> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_volatile_reference_v = is_volatile_reference<_Type>::value;
#endif

/*
 *      _                     _            _      _   _ _                __
 *     (_)___  __ ___ _ _  __| |_ __ _____| |__ _| |_(_) |___   _ _ ___ / _|___ _ _ ___ _ _  __ ___
 *     | (_-< / _/ _ \ ' \(_-<  _|\ V / _ \ / _` |  _| | / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     |_/__/_\__\___/_||_/__/\__|_\_/\___/_\__,_|\__|_|_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *         |___|                |___|                       |___|
 */

template <typename _Type>
struct is_const_volatile_reference
	: boolean_constant<is_reference<_Type>::value && is_const_volatile<remove_reference_t<_Type>>::value> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_const_volatile_reference_v = is_const_volatile_reference<_Type>::value;
#endif

/*
 *      _      _          _                     __                         
 *     (_)___ | |_ ____ _| |_  _ ___   _ _ ___ / _|___ _ _ ___ _ _  __ ___ 
 *     | (_-< | \ V / _` | | || / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     |_/__/_|_|\_/\__,_|_|\_,_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *         |___|                   |___|                                   
 */

template <typename _Type>
struct is_lvalue_reference : false_t {};

template <typename _Type>
struct is_lvalue_reference<_Type&> : true_t {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_lvalue_reference_v = is_lvalue_reference<_Type>::value;
#endif

/*
 *      _                     _     _          _                     __                         
 *     (_)___  __ ___ _ _  __| |_  | |_ ____ _| |_  _ ___   _ _ ___ / _|___ _ _ ___ _ _  __ ___ 
 *     | (_-< / _/ _ \ ' \(_-<  _| | \ V / _` | | || / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     |_/__/_\__\___/_||_/__/\__|_|_|\_/\__,_|_|\_,_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *         |___|                |___|                   |___|                                   
 */

template <typename _Type>
struct is_const_lvalue_reference : false_t {};

template <typename _Type>
struct is_const_lvalue_reference<const _Type&> : true_t {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_const_lvalue_reference_v = is_const_lvalue_reference<_Type>::value;
#endif

/*
 *      _             _      _   _ _       _          _                     __                         
 *     (_)_____ _____| |__ _| |_(_) |___  | |_ ____ _| |_  _ ___   _ _ ___ / _|___ _ _ ___ _ _  __ ___ 
 *     | (_-<\ V / _ \ / _` |  _| | / -_) | \ V / _` | | || / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     |_/__/_\_/\___/_\__,_|\__|_|_\___|_|_|\_/\__,_|_|\_,_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *         |___|                       |___|                   |___|                                   
 */

template <typename _Type>
struct is_volatile_lvalue_reference : false_t {};

template <typename _Type>
struct is_volatile_lvalue_reference<volatile _Type&> : true_t {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_volatile_lvalue_reference_v = is_volatile_lvalue_reference<_Type>::value;
#endif

/*
 *      _                     _            _      _   _ _       _          _                     __                         
 *     (_)___  __ ___ _ _  __| |_ __ _____| |__ _| |_(_) |___  | |_ ____ _| |_  _ ___   _ _ ___ / _|___ _ _ ___ _ _  __ ___ 
 *     | (_-< / _/ _ \ ' \(_-<  _|\ V / _ \ / _` |  _| | / -_) | \ V / _` | | || / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     |_/__/_\__\___/_||_/__/\__|_\_/\___/_\__,_|\__|_|_\___|_|_|\_/\__,_|_|\_,_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *         |___|                |___|                       |___|                   |___|                                   
 */

template <typename _Type>
struct is_const_volatile_lvalue_reference 
	: boolean_constant<is_const_lvalue_reference<_Type>::value || is_volatile_lvalue_reference<_Type>::value> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_const_volatile_lvalue_reference_v = is_const_volatile_lvalue_reference<_Type>::value;
#endif

/*
 *      _                   _                     __                         
 *     (_)___  _ ___ ____ _| |_  _ ___   _ _ ___ / _|___ _ _ ___ _ _  __ ___ 
 *     | (_-< | '_\ V / _` | | || / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     |_/__/_|_|  \_/\__,_|_|\_,_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *         |___|                     |___|                                   
 */

template <typename _Type>
struct is_rvalue_reference : false_t {};

template <typename _Type>
struct is_rvalue_reference<_Type&&> : true_t {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_rvalue_reference_v = is_rvalue_reference<_Type>::value;
#endif

/*
 *      _                     _                  _                     __                         
 *     (_)___  __ ___ _ _  __| |_   _ ___ ____ _| |_  _ ___   _ _ ___ / _|___ _ _ ___ _ _  __ ___ 
 *     | (_-< / _/ _ \ ' \(_-<  _| | '_\ V / _` | | || / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     |_/__/_\__\___/_||_/__/\__|_|_|  \_/\__,_|_|\_,_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *         |___|                |___|                     |___|                                   
 */

template <typename _Type>
struct is_const_rvalue_reference : false_t {};

template <typename _Type>
struct is_const_rvalue_reference<const _Type&&> : true_t {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_const_rvalue_reference_v = is_const_rvalue_reference<_Type>::value;
#endif

/*
 *      _             _      _   _ _                    _                     __                         
 *     (_)_____ _____| |__ _| |_(_) |___   _ ___ ____ _| |_  _ ___   _ _ ___ / _|___ _ _ ___ _ _  __ ___ 
 *     | (_-<\ V / _ \ / _` |  _| | / -_) | '_\ V / _` | | || / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     |_/__/_\_/\___/_\__,_|\__|_|_\___|_|_|  \_/\__,_|_|\_,_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *         |___|                       |___|                     |___|                                   
 */

template <typename _Type>
struct is_volatile_rvalue_reference : false_t {};

template <typename _Type>
struct is_volatile_rvalue_reference<volatile _Type&&> : true_t {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_volatile_rvalue_reference_v = is_volatile_rvalue_reference<_Type>::value;
#endif

/*
 *      _                     _            _      _   _ _                    _                     __                         
 *     (_)___  __ ___ _ _  __| |_ __ _____| |__ _| |_(_) |___   _ ___ ____ _| |_  _ ___   _ _ ___ / _|___ _ _ ___ _ _  __ ___ 
 *     | (_-< / _/ _ \ ' \(_-<  _|\ V / _ \ / _` |  _| | / -_) | '_\ V / _` | | || / -_) | '_/ -_)  _/ -_) '_/ -_) ' \/ _/ -_)
 *     |_/__/_\__\___/_||_/__/\__|_\_/\___/_\__,_|\__|_|_\___|_|_|  \_/\__,_|_|\_,_\___|_|_| \___|_| \___|_| \___|_||_\__\___|
 *         |___|                |___|                       |___|                     |___|                                   
 */

template <typename _Type>
struct is_const_volatile_rvalue_reference 
	: boolean_constant<is_const_rvalue_reference<_Type>::value || is_volatile_rvalue_reference<_Type>::value> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_const_volatile_rvalue_reference_v = is_const_volatile_rvalue_reference<_Type>::value;
#endif

/*
 *      _                 _     _           
 *     (_)___   _ __  ___(_)_ _| |_ ___ _ _ 
 *     | (_-<  | '_ \/ _ \ | ' \  _/ -_) '_|
 *     |_/__/__| .__/\___/_|_||_\__\___|_|  
 *         |___|_|                          
 */

template <typename _Type>
struct is_pointer : false_t {};

template <typename _Type>
struct is_pointer<_Type*> : true_t {};

template <typename _Type>
struct is_pointer<_Type* const> : true_t {};

template <typename _Type>
struct is_pointer<_Type* volatile> : true_t {};

template <typename _Type>
struct is_pointer<_Type* const volatile> : true_t {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_pointer_v = is_pointer<_Type>::value;
#endif

/*
 *      _                     _                _     _           
 *     (_)___  __ ___ _ _  __| |_    _ __  ___(_)_ _| |_ ___ _ _ 
 *     | (_-< / _/ _ \ ' \(_-<  _|  | '_ \/ _ \ | ' \  _/ -_) '_|
 *     |_/__/_\__\___/_||_/__/\__|__| .__/\___/_|_||_\__\___|_|  
 *         |___|                |___|_|                          
 */

template <typename _Type>
struct is_const_pointer
	: boolean_constant<is_pointer<_Type>::value && is_const<remove_pointer_t<_Type>>::value> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_const_pointer_v = is_const_pointer<_Type>::value;
#endif

/*
 *      _             _      _   _ _                  _     _
 *     (_)_____ _____| |__ _| |_(_) |___    _ __  ___(_)_ _| |_ ___ _ _
 *     | (_-<\ V / _ \ / _` |  _| | / -_)  | '_ \/ _ \ | ' \  _/ -_) '_|
 *     |_/__/_\_/\___/_\__,_|\__|_|_\___|__| .__/\___/_|_||_\__\___|_|
 *         |___|                       |___|_|
 */

template <typename _Type>
struct is_volatile_pointer
	: boolean_constant<is_pointer<_Type>::value && is_volatile<remove_pointer_t<_Type>>::value> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_volatile_pointer_v = is_volatile_pointer<_Type>::value;
#endif

/*
 *      _                     _            _      _   _ _                  _     _
 *     (_)___  __ ___ _ _  __| |_ __ _____| |__ _| |_(_) |___    _ __  ___(_)_ _| |_ ___ _ _
 *     | (_-< / _/ _ \ ' \(_-<  _|\ V / _ \ / _` |  _| | / -_)  | '_ \/ _ \ | ' \  _/ -_) '_|
 *     |_/__/_\__\___/_||_/__/\__|_\_/\___/_\__,_|\__|_|_\___|__| .__/\___/_|_||_\__\___|_|
 *         |___|                |___|                       |___|_|
 */

template <typename _Type>
struct is_const_volatile_pointer
	: boolean_constant<is_pointer<_Type>::value && is_const_volatile<remove_pointer_t<_Type>>::value> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_const_volatile_pointer_v = is_const_volatile_pointer<_Type>::value;
#endif

/*
 *      _                      _           _   
 *     | |_  __ _ ___  _____ _| |_ ___ _ _| |_ 
 *     | ' \/ _` (_-< / -_) \ /  _/ -_) ' \  _|
 *     |_||_\__,_/__/_\___/_\_\\__\___|_||_\__|
 *                 |___|                       
 */

template <typename _Type>
struct has_extent : false_t {};

template <typename _Type>
struct has_extent<_Type[]> : true_t {};

template <typename _Type, unsigned _Size>
struct has_extent<_Type[_Size]> : true_t {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool has_extent_v = has_extent<_Type>::value;
#endif

/*
 *      _              _                      _        _           _           _
 *     | |_  __ _ ___ | |__  ___ _  _ _ _  __| |___ __| |  _____ _| |_ ___ _ _| |_
 *     | ' \/ _` (_-< | '_ \/ _ \ || | ' \/ _` / -_) _` | / -_) \ /  _/ -_) ' \  _|
 *     |_||_\__,_/__/_|_.__/\___/\_,_|_||_\__,_\___\__,_|_\___/_\_\\__\___|_||_\__|
 *                 |___|                               |___|
 */

template <typename _Type>
struct has_bounded_extent : false_t {};

template <typename _Type, unsigned _Size>
struct has_bounded_extent<_Type[_Size]> : true_t {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool has_bounded_extent_v = has_bounded_extent<_Type>::value;
#endif

/*
 *      _                       _                      _        _           _           _
 *     | |_  __ _ ___ _  _ _ _ | |__  ___ _  _ _ _  __| |___ __| |  _____ _| |_ ___ _ _| |_
 *     | ' \/ _` (_-<| || | ' \| '_ \/ _ \ || | ' \/ _` / -_) _` | / -_) \ /  _/ -_) ' \  _|
 *     |_||_\__,_/__/_\_,_|_||_|_.__/\___/\_,_|_||_\__,_\___\__,_|_\___/_\_\\__\___|_||_\__|
 *                 |___|                                        |___|
 */

template <typename _Type>
struct has_unbounded_extent : false_t {};

template <typename _Type>
struct has_unbounded_extent<_Type[]> : true_t {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool has_unbounded_extent_v = has_unbounded_extent<_Type>::value;
#endif

/*
 *                     _ _ _   _               _
 *      __ ___ _ _  __| (_) |_(_)___ _ _  __ _| |
 *     / _/ _ \ ' \/ _` | |  _| / _ \ ' \/ _` | |
 *     \__\___/_||_\__,_|_|\__|_\___/_||_\__,_|_|
 *
 */

template <bool _Condition, typename _TType, typename _FType>
struct conditional : identity<_TType> {};

template <typename _TType, typename _FType>
struct conditional<false, _TType, _FType> : identity<_FType> {};

template <bool _Condition, typename _TType, typename _FType>
using conditional_t = typename conditional<_Condition, _TType, _FType>::type;

/*
 *                   _              _   _
 *      __ ___ _ _  (_)_  _ _ _  __| |_(_)___ _ _
 *     / _/ _ \ ' \ | | || | ' \/ _|  _| / _ \ ' \
 *     \__\___/_||_|/ |\_,_|_||_\__|\__|_\___/_||_|
 *                |__/
 */

template <typename... _Types>
struct conjunction : true_t {};

template <typename _Type>
struct conjunction<_Type> : _Type {};

template <typename _Type, typename... _Rest>
struct conjunction<_Type, _Rest...>
	: conditional_t<bool(_Type::value), conjunction<_Rest...>, _Type> {
};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename... _Types>
	_EXTYPETRAITS_INLINE17 constexpr bool conjunction_v = conjunction<_Types...>::value;
#endif

/*
 *         _ _     _              _   _
 *      __| (_)___(_)_  _ _ _  __| |_(_)___ _ _
 *     / _` | (_-<| | || | ' \/ _|  _| / _ \ ' \
 *     \__,_|_/__// |\_,_|_||_\__|\__|_\___/_||_|
 *              |__/
 */

template <typename... _Types>
struct disjunction : false_t {};

template <typename _Type>
struct disjunction<_Type> : _Type {};

template <typename _Type, typename... _Rest>
struct disjunction<_Type, _Rest...>
	: conditional_t<bool(_Type::value), _Type, disjunction<_Rest...>> {
};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename... _Types>
	_EXTYPETRAITS_INLINE17 constexpr bool disjunction_v = disjunction<_Types...>::value;
#endif

/*
 *                         _   _
 *      _ _  ___ __ _ __ _| |_(_)___ _ _
 *     | ' \/ -_) _` / _` |  _| / _ \ ' \
 *     |_||_\___\__, \__,_|\__|_\___/_||_|
 *              |___/
 */

template <typename _Type>
struct negation : boolean_constant<!bool(_Type::value)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool negation_v = negation<_Type>::value;
#endif

/*
 *      _
 *     (_)___  ___ __ _ _ __  ___
 *     | (_-< (_-</ _` | '  \/ -_)
 *     |_/__/_/__/\__,_|_|_|_\___|
 *         |___|
 */

template <typename _Type1, typename _Type2>
struct is_same : false_t {};

template <typename _Type>
struct is_same<_Type, _Type> : true_t {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type1, typename _Type2>
	_EXTYPETRAITS_INLINE17 constexpr bool is_same_v = is_same<_Type1, _Type2>::value;
#endif

/*
 *      _         _ _  __  __                 _
 *     (_)___  __| (_)/ _|/ _|___ _ _ ___ _ _| |_
 *     | (_-< / _` | |  _|  _/ -_) '_/ -_) ' \  _|
 *     |_/__/_\__,_|_|_| |_| \___|_| \___|_||_\__|
 *         |___|
 */

template <typename _Type1, typename _Type2>
struct is_different : true_t {};

template <typename _Type>
struct is_different<_Type, _Type> : false_t {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type1, typename _Type2>
	_EXTYPETRAITS_INLINE17 constexpr bool is_different_v = is_different<_Type1, _Type2>::value;
#endif

/*
 *      _                           __ 
 *     (_)___  __ _ _ _ _  _   ___ / _|
 *     | (_-< / _` | ' \ || | / _ \  _|
 *     |_/__/_\__,_|_||_\_, |_\___/_|  
 *         |___|        |__/___|       
 */

template <typename _Type, typename... _Types>
struct is_any_of : false_t {};

template <typename _Type, typename _First, typename... _Rest>
struct is_any_of<_Type, _First, _Rest...> 
	: conditional_t<is_same<_Type, _First>::value, true_t, is_any_of<_Type, _Rest...>> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type, typename... _Types>
	_EXTYPETRAITS_INLINE17 constexpr bool is_any_of_v = is_any_of<_Type, _Types...>::value;
#endif

/*
 *      _                               __ 
 *     (_)___  _ _  ___ _ _  ___   ___ / _|
 *     | (_-< | ' \/ _ \ ' \/ -_) / _ \  _|
 *     |_/__/_|_||_\___/_||_\___|_\___/_|  
 *         |___|               |___|       
 */

template <typename _Type, typename... _Types>
struct is_none_of : true_t {};

template <typename _Type, typename _First, typename... _Rest>
struct is_none_of<_Type, _First, _Rest...> 
	: conditional_t<is_same<_Type, _First>::value, false_t, is_none_of<_Type, _Rest...>> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type, typename... _Types>
	_EXTYPETRAITS_INLINE17 constexpr bool is_none_of_v = is_none_of<_Type, _Types...>::value;
#endif

/*
 *      _             _    _
 *     (_)_____ _____(_)__| |
 *     | (_-<\ V / _ \ / _` |
 *     |_/__/_\_/\___/_\__,_|
 *         |___|
 */

template <typename _Type>
struct is_void : is_same<void, remove_const_volatile_t<_Type>> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_void_v = is_void<_Type>::value;
#endif

/*
 *      _               _            _    _ 
 *     (_)___  _ _  ___| |_ __ _____(_)__| |
 *     | (_-< | ' \/ _ \  _|\ V / _ \ / _` |
 *     |_/__/_|_||_\___/\__|_\_/\___/_\__,_|
 *         |___|          |___|             
 */

template <typename _Type>
struct is_not_void : boolean_constant<!is_same<void, remove_const_volatile_t<_Type>>::value> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_void_v = is_not_void<_Type>::value;
#endif

/*
 *      _               _ _              _     _
 *     (_)___  _ _ _  _| | |   _ __  ___(_)_ _| |_ ___ _ _
 *     | (_-< | ' \ || | | |  | '_ \/ _ \ | ' \  _/ -_) '_|
 *     |_/__/_|_||_\_,_|_|_|__| .__/\___/_|_||_\__\___|_|
 *         |___|          |___|_|
 */

template <typename _Type>
struct is_null_pointer : is_same<std::nullptr_t, remove_const_volatile_t<_Type>> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_null_pointer_v = is_null_pointer<_Type>::value;
#endif

/*
 *      _               _              _ _              _     _           
 *     (_)___  _ _  ___| |_   _ _ _  _| | |   _ __  ___(_)_ _| |_ ___ _ _ 
 *     | (_-< | ' \/ _ \  _| | ' \ || | | |  | '_ \/ _ \ | ' \  _/ -_) '_|
 *     |_/__/_|_||_\___/\__|_|_||_\_,_|_|_|__| .__/\___/_|_||_\__\___|_|  
 *         |___|          |___|          |___|_|                          
 */

template <typename _Type>
struct is_not_null_pointer : boolean_constant<!is_same<std::nullptr_t, remove_const_volatile_t<_Type>>::value> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_null_pointer_v = is_not_null_pointer<_Type>::value;
#endif

/*
 *      _      _     _                     _ 
 *     (_)___ (_)_ _| |_ ___ __ _ _ _ __ _| |
 *     | (_-< | | ' \  _/ -_) _` | '_/ _` | |
 *     |_/__/_|_|_||_\__\___\__, |_| \__,_|_|
 *         |___|            |___/            
 */

template <typename _Type>
struct is_integral : is_any_of<remove_const_volatile_t<_Type>,
	bool, char, signed char, unsigned char, wchar_t,
#	if defined(__cpp_char8_t)
		char8_t,
#	endif
	char16_t, char32_t, short, unsigned short, int, unsigned int,
	long, unsigned long, long long, unsigned long long> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_integral_v = is_integral<_Type>::value;
#endif

/*
 *      _               _     _     _                     _ 
 *     (_)___  _ _  ___| |_  (_)_ _| |_ ___ __ _ _ _ __ _| |
 *     | (_-< | ' \/ _ \  _| | | ' \  _/ -_) _` | '_/ _` | |
 *     |_/__/_|_||_\___/\__|_|_|_||_\__\___\__, |_| \__,_|_|
 *         |___|          |___|            |___/            
 */

template <typename _Type>
struct is_not_integral : boolean_constant<!is_any_of<remove_const_volatile_t<_Type>,
	bool, char, signed char, unsigned char, wchar_t,
#	if defined(__cpp_char8_t)
		char8_t,
#	endif
	char16_t, char32_t, short, unsigned short, int, unsigned int,
	long, unsigned long, long long, unsigned long long>::value> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_integral_v = is_not_integral<_Type>::value;
#endif

/*
 *      _                    _              _   _     _                     _ 
 *     (_)___  _ _  ___ _ _ | |__  ___  ___| | (_)_ _| |_ ___ __ _ _ _ __ _| |
 *     | (_-< | ' \/ _ \ ' \| '_ \/ _ \/ _ \ | | | ' \  _/ -_) _` | '_/ _` | |
 *     |_/__/_|_||_\___/_||_|_.__/\___/\___/_|_|_|_||_\__\___\__, |_| \__,_|_|
 *         |___|                            |___|            |___/            
 */

template <typename _Type>
struct is_nonbool_integral 
	: boolean_constant<is_different<remove_const_volatile_t<_Type>, bool>::value && is_integral<_Type>::value> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_nonbool_integral_v = is_nonbool_integral<_Type>::value;
#endif

/*
 *      _               _                   _              _   _     _                     _ 
 *     (_)___  _ _  ___| |_   _ _  ___ _ _ | |__  ___  ___| | (_)_ _| |_ ___ __ _ _ _ __ _| |
 *     | (_-< | ' \/ _ \  _| | ' \/ _ \ ' \| '_ \/ _ \/ _ \ | | | ' \  _/ -_) _` | '_/ _` | |
 *     |_/__/_|_||_\___/\__|_|_||_\___/_||_|_.__/\___/\___/_|_|_|_||_\__\___\__, |_| \__,_|_|
 *         |___|          |___|                            |___|            |___/            
 */

template <typename _Type>
struct is_not_nonbool_integral 
	: boolean_constant<!(is_different<remove_const_volatile_t<_Type>, bool>::value && is_integral<_Type>::value)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_nonbool_integral_v = is_not_nonbool_integral<_Type>::value;
#endif

/*
 *      _       __ _           _   _                        _     _   
 *     (_)___  / _| |___  __ _| |_(_)_ _  __ _    _ __  ___(_)_ _| |_ 
 *     | (_-< |  _| / _ \/ _` |  _| | ' \/ _` |  | '_ \/ _ \ | ' \  _|
 *     |_/__/_|_| |_\___/\__,_|\__|_|_||_\__, |__| .__/\___/_|_||_\__|
 *         |___|                         |___/___|_|                  
 */

template <typename _Type>
struct is_floating_point
	: is_any_of<remove_const_volatile_t<_Type>, float, double, long double> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_floating_point_v = is_floating_point<_Type>::value;
#endif

/*
 *      _               _      __ _           _   _                        _     _   
 *     (_)___  _ _  ___| |_   / _| |___  __ _| |_(_)_ _  __ _    _ __  ___(_)_ _| |_ 
 *     | (_-< | ' \/ _ \  _| |  _| / _ \/ _` |  _| | ' \/ _` |  | '_ \/ _ \ | ' \  _|
 *     |_/__/_|_||_\___/\__|_|_| |_\___/\__,_|\__|_|_||_\__, |__| .__/\___/_|_||_\__|
 *         |___|          |___|                         |___/___|_|                  
 */

template <typename _Type>
struct is_not_floating_point
	: boolean_constant<!is_any_of<remove_const_volatile_t<_Type>, float, double, long double>::value> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_floating_point_v = is_not_floating_point<_Type>::value;
#endif

/*
 *      _               _ _   _              _   _    
 *     (_)___  __ _ _ _(_) |_| |_  _ __  ___| |_(_)__ 
 *     | (_-< / _` | '_| |  _| ' \| '  \/ -_)  _| / _|
 *     |_/__/_\__,_|_| |_|\__|_||_|_|_|_\___|\__|_\__|
 *         |___|                                      
 */

template <typename _Type>
struct is_arithmetic 
	: boolean_constant<is_integral<_Type>::value || is_floating_point<_Type>::value> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_arithmetic_v = is_arithmetic<_Type>::value;
#endif

/*
 *      _               _              _ _   _              _   _    
 *     (_)___  _ _  ___| |_   __ _ _ _(_) |_| |_  _ __  ___| |_(_)__ 
 *     | (_-< | ' \/ _ \  _| / _` | '_| |  _| ' \| '  \/ -_)  _| / _|
 *     |_/__/_|_||_\___/\__|_\__,_|_| |_|\__|_||_|_|_|_\___|\__|_\__|
 *         |___|          |___|                                      
 */

template <typename _Type>
struct is_not_arithmetic 
	: boolean_constant<!(is_integral<_Type>::value || is_floating_point<_Type>::value)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_arithmetic_v = is_not_arithmetic<_Type>::value;
#endif

/*
 *      _            _      _           _      _        
 *     (_)___   _ __| |__ _(_)_ _    __| |__ _| |_ __ _ 
 *     | (_-<  | '_ \ / _` | | ' \  / _` / _` |  _/ _` |
 *     |_/__/__| .__/_\__,_|_|_||_|_\__,_\__,_|\__\__,_|
 *         |___|_|               |___|                  
 */

template <typename _Type>
struct is_plain_data : boolean_constant<__is_pod(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_plain_data_v = is_plain_data<_Type>::value;
#endif

/*
 *      _               _           _      _           _      _        
 *     (_)___  _ _  ___| |_    _ __| |__ _(_)_ _    __| |__ _| |_ __ _ 
 *     | (_-< | ' \/ _ \  _|  | '_ \ / _` | | ' \  / _` / _` |  _/ _` |
 *     |_/__/_|_||_\___/\__|__| .__/_\__,_|_|_||_|_\__,_\__,_|\__\__,_|
 *         |___|          |___|_|               |___|                  
 */

template <typename _Type>
struct is_not_plain_data : boolean_constant<!__is_pod(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_plain_data_v = is_not_plain_data<_Type>::value;
#endif

/*
 *      _     _       _     _      _ 
 *     (_)___| |_ _ _(_)_ _(_)__ _| |
 *     | (_-<|  _| '_| \ V / / _` | |
 *     |_/__/_\__|_| |_|\_/|_\__,_|_|
 *         |___|                     
 */

template <typename _Type>
struct is_trivial : boolean_constant<__is_trivial(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_trivial_v = is_trivial<_Type>::value;
#endif

/*
 *      _               _    _       _     _      _ 
 *     (_)___  _ _  ___| |_ | |_ _ _(_)_ _(_)__ _| |
 *     | (_-< | ' \/ _ \  _||  _| '_| \ V / / _` | |
 *     |_/__/_|_||_\___/\__|_\__|_| |_|\_/|_\__,_|_|
 *         |___|          |___|                     
 */

template <typename _Type>
struct is_not_trivial : boolean_constant<!__is_trivial(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_trivial_v = is_not_trivial<_Type>::value;
#endif

/*
 *      _                         
 *     (_)___  ___ _ _ _  _ _ __  
 *     | (_-< / -_) ' \ || | '  \ 
 *     |_/__/_\___|_||_\_,_|_|_|_|
 *         |___|                  
 */

template <typename _Type>
struct is_enum : boolean_constant<__is_enum(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_enum_v = is_enum<_Type>::value;
#endif

/*
 *      _               _                        
 *     (_)___  _ _  ___| |_   ___ _ _ _  _ _ __  
 *     | (_-< | ' \/ _ \  _| / -_) ' \ || | '  \ 
 *     |_/__/_|_||_\___/\__|_\___|_||_\_,_|_|_|_|
 *         |___|          |___|                  
 */

template <typename _Type>
struct is_not_enum : boolean_constant<!__is_enum(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_enum_v = is_not_enum<_Type>::value;
#endif

/*
 *                   _         _      _            _                  
 *      _  _ _ _  __| |___ _ _| |_  _(_)_ _  __ _ | |_ _  _ _ __  ___ 
 *     | || | ' \/ _` / -_) '_| | || | | ' \/ _` ||  _| || | '_ \/ -_)
 *      \_,_|_||_\__,_\___|_| |_|\_, |_|_||_\__, |_\__|\_, | .__/\___|
 *                               |__/       |___/___|  |__/|_|        
 */

#if _EXTYPETRAITS_HAS_CXX20
	template <typename _Type>
		requires is_enum_v<_Type>
	struct underlying_type : identity<__underlying_type(_Type)> {};
#else
	template <typename _Type, typename = enable_if_t<is_enum<_Type>::value>>
	struct underlying_type : identity<__underlying_type(_Type)> {};
#endif

template <typename _Type>
using underlying_type_t = typename underlying_type<_Type>::type;

/*
 *      _       __              _   _
 *     (_)___  / _|_  _ _ _  __| |_(_)___ _ _
 *     | (_-< |  _| || | ' \/ _|  _| / _ \ ' \
 *     |_/__/_|_|  \_,_|_||_\__|\__|_\___/_||_|
 *         |___|
 */

template <typename _Type>
struct is_function : boolean_constant<!is_const<const _Type>::value && !is_reference<_Type>::value> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_function_v = is_function<_Type>::value;
#endif

/*
 *      _               _      __              _   _          
 *     (_)___  _ _  ___| |_   / _|_  _ _ _  __| |_(_)___ _ _  
 *     | (_-< | ' \/ _ \  _| |  _| || | ' \/ _|  _| / _ \ ' \ 
 *     |_/__/_|_||_\___/\__|_|_|  \_,_|_||_\__|\__|_\___/_||_|
 *         |___|          |___|                               
 */

template <typename _Type>
struct is_not_function : boolean_constant<!(!is_const<const _Type>::value && !is_reference<_Type>::value)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_function_v = is_not_function<_Type>::value;
#endif

/*
 *      _                      _              __              _   _                       _     _           
 *     (_)___  _ __  ___ _ __ | |__  ___ _ _ / _|_  _ _ _  __| |_(_)___ _ _     _ __  ___(_)_ _| |_ ___ _ _ 
 *     | (_-< | '  \/ -_) '  \| '_ \/ -_) '_|  _| || | ' \/ _|  _| / _ \ ' \   | '_ \/ _ \ | ' \  _/ -_) '_|
 *     |_/__/_|_|_|_\___|_|_|_|_.__/\___|_|_|_|  \_,_|_||_\__|\__|_\___/_||_|__| .__/\___/_|_||_\__\___|_|  
 *         |___|                         |___|                             |___|_|                          
 */

#if _EXTYPETRAITS_CLANG
	template <typename _Type>
	struct is_member_function_pointer : boolean_constant<__is_member_function_pointer(_Type)> {};
#else
	template <typename _Type>
	struct _is_memfunptr_impl : false_t {};

	template <typename _Type, typename _ClassType>
	struct _is_memfunptr_impl<_Type _ClassType::*> : is_function<_Type> {};

	template <typename _Type>
	struct is_member_function_pointer : _is_memfunptr_impl<remove_const_volatile_t<_Type>> {};
#endif

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_member_function_pointer_v = is_member_function_pointer<_Type>::value;
#endif

/*
 *      _               _                     _              __              _   _                       _     _           
 *     (_)___  _ _  ___| |_   _ __  ___ _ __ | |__  ___ _ _ / _|_  _ _ _  __| |_(_)___ _ _     _ __  ___(_)_ _| |_ ___ _ _ 
 *     | (_-< | ' \/ _ \  _| | '  \/ -_) '  \| '_ \/ -_) '_|  _| || | ' \/ _|  _| / _ \ ' \   | '_ \/ _ \ | ' \  _/ -_) '_|
 *     |_/__/_|_||_\___/\__|_|_|_|_\___|_|_|_|_.__/\___|_|_|_|  \_,_|_||_\__|\__|_\___/_||_|__| .__/\___/_|_||_\__\___|_|  
 *         |___|          |___|                         |___|                             |___|_|                          
 */

#if _EXTYPETRAITS_CLANG
	template <typename _Type>
	struct is_not_member_function_pointer : boolean_constant<__is_member_function_pointer(_Type)> {};
#else
	template <typename _Type>
	struct _is_not_memfunptr_impl : true_t {};

	template <typename _Type, typename _ClassType>
	struct _is_not_memfunptr_impl<_Type _ClassType::*> : boolean_constant<!is_function<_Type>::value> {};

	template <typename _Type>
	struct is_not_member_function_pointer : _is_not_memfunptr_impl<remove_const_volatile_t<_Type>> {};
#endif

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_member_function_pointer_v = is_not_member_function_pointer<_Type>::value;
#endif

/*
 *      _                      _                 _     _        _                _     _           
 *     (_)___  _ __  ___ _ __ | |__  ___ _ _ ___| |__ (_)___ __| |_    _ __  ___(_)_ _| |_ ___ _ _ 
 *     | (_-< | '  \/ -_) '  \| '_ \/ -_) '_/ _ \ '_ \| / -_) _|  _|  | '_ \/ _ \ | ' \  _/ -_) '_|
 *     |_/__/_|_|_|_\___|_|_|_|_.__/\___|_|_\___/_.__// \___\__|\__|__| .__/\___/_|_||_\__\___|_|  
 *         |___|                         |___|      |__/          |___|_|                          
 */

#if _EXTYPETRAITS_CLANG
	template <typename _Type>
	struct is_member_object_pointer : boolean_constant<__is_member_object_pointer(_Type)> {};
#else
	template <typename _Type>
	struct _is_memobjptr_impl : false_t {};

	template <typename _Type, typename _ClassType>
	struct _is_memobjptr_impl<_Type _ClassType::*> : boolean_constant<!is_function<_Type>::value> {};

	template <typename _Type>
	struct is_member_object_pointer : _is_memobjptr_impl<remove_const_volatile_t<_Type>> {};
#endif

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_member_object_pointer_v = is_member_object_pointer<_Type>::value;
#endif

/*
 *      _               _                     _                 _     _        _                _     _           
 *     (_)___  _ _  ___| |_   _ __  ___ _ __ | |__  ___ _ _ ___| |__ (_)___ __| |_    _ __  ___(_)_ _| |_ ___ _ _ 
 *     | (_-< | ' \/ _ \  _| | '  \/ -_) '  \| '_ \/ -_) '_/ _ \ '_ \| / -_) _|  _|  | '_ \/ _ \ | ' \  _/ -_) '_|
 *     |_/__/_|_||_\___/\__|_|_|_|_\___|_|_|_|_.__/\___|_|_\___/_.__// \___\__|\__|__| .__/\___/_|_||_\__\___|_|  
 *         |___|          |___|                         |___|      |__/          |___|_|                          
 */

#if _EXTYPETRAITS_CLANG
	template <typename _Type>
	struct is_not_member_object_pointer : boolean_constant<!__is_member_object_pointer(_Type)> {};
#else
	template <typename _Type>
	struct _is_not_memobjptr_impl : true_t {};

	template <typename _Type, typename _ClassType>
	struct _is_not_memobjptr_impl<_Type _ClassType::*> : boolean_constant<is_function<_Type>::value> {};

	template <typename _Type>
	struct is_not_member_object_pointer : _is_not_memobjptr_impl<remove_const_volatile_t<_Type>> {};
#endif

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_member_object_pointer_v = is_not_member_object_pointer<_Type>::value;
#endif

/*
 *      _                      _                        _     _           
 *     (_)___  _ __  ___ _ __ | |__  ___ _ _  _ __  ___(_)_ _| |_ ___ _ _ 
 *     | (_-< | '  \/ -_) '  \| '_ \/ -_) '_|| '_ \/ _ \ | ' \  _/ -_) '_|
 *     |_/__/_|_|_|_\___|_|_|_|_.__/\___|_|__| .__/\___/_|_||_\__\___|_|  
 *         |___|                         |___|_|                          
 */

#if _EXTYPETRAITS_CLANG
	template <typename _Type>
	struct is_member_pointer : boolean_constant<__is_member_pointer(_Type)> {};
#else
	template <typename _Type>
	struct is_member_pointer
		: boolean_constant<is_member_function_pointer<_Type>::value || is_member_object_pointer<_Type>::value> {};
#endif

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_member_pointer_v = is_member_pointer<_Type>::value;
#endif

/*
 *      _               _                     _                        _     _           
 *     (_)___  _ _  ___| |_   _ __  ___ _ __ | |__  ___ _ _  _ __  ___(_)_ _| |_ ___ _ _ 
 *     | (_-< | ' \/ _ \  _| | '  \/ -_) '  \| '_ \/ -_) '_|| '_ \/ _ \ | ' \  _/ -_) '_|
 *     |_/__/_|_||_\___/\__|_|_|_|_\___|_|_|_|_.__/\___|_|__| .__/\___/_|_||_\__\___|_|  
 *         |___|          |___|                         |___|_|                          
 */

#if _EXTYPETRAITS_CLANG
	template <typename _Type>
	struct is_not_member_pointer : boolean_constant<!__is_member_pointer(_Type)> {};
#else
	template <typename _Type>
	struct is_not_member_pointer
		: boolean_constant<!(is_member_function_pointer<_Type>::value || is_member_object_pointer<_Type>::value)> {};
#endif

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_member_pointer_v = is_not_member_pointer<_Type>::value;
#endif

/*
 *      _       __              _                    _        _ 
 *     (_)___  / _|_  _ _ _  __| |__ _ _ __  ___ _ _| |_ __ _| |
 *     | (_-< |  _| || | ' \/ _` / _` | '  \/ -_) ' \  _/ _` | |
 *     |_/__/_|_|  \_,_|_||_\__,_\__,_|_|_|_\___|_||_\__\__,_|_|
 *         |___|                                                
 */

template <typename _Type>
struct is_fundamental
	: boolean_constant<is_arithmetic<_Type>::value || is_void<_Type>::value || is_null_pointer<_Type>::value> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_fundamental_v = is_fundamental<_Type>::value;
#endif

/*
 *      _                                          _ 
 *     (_)___  __ ___ _ __  _ __  ___ _  _ _ _  __| |
 *     | (_-< / _/ _ \ '  \| '_ \/ _ \ || | ' \/ _` |
 *     |_/__/_\__\___/_|_|_| .__/\___/\_,_|_||_\__,_|
 *         |___|           |_|                       
 */

template <typename _Type>
struct is_compound : boolean_constant<!is_fundamental<_Type>::value> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_compound_v = is_compound<_Type>::value;
#endif

/*
 *      _                  _          
 *     (_)___  ___ __ __ _| |__ _ _ _ 
 *     | (_-< (_-</ _/ _` | / _` | '_|
 *     |_/__/_/__/\__\__,_|_\__,_|_|  
 *         |___|                      
 */

template <typename _Type>
struct is_scalar 
	: boolean_constant<is_arithmetic<_Type>::value || is_enum<_Type>::value || is_pointer<_Type>::value
		|| is_member_pointer<_Type>::value || is_null_pointer<_Type>::value> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_scalar_v = is_scalar<_Type>::value;
#endif

/*
 *      _               _                 _          
 *     (_)___  _ _  ___| |_   ___ __ __ _| |__ _ _ _ 
 *     | (_-< | ' \/ _ \  _| (_-</ _/ _` | / _` | '_|
 *     |_/__/_|_||_\___/\__|_/__/\__\__,_|_\__,_|_|  
 *         |___|          |___|                      
 */

template <typename _Type>
struct is_not_scalar 
	: boolean_constant<!(is_arithmetic<_Type>::value || is_enum<_Type>::value || is_pointer<_Type>::value
		|| is_member_pointer<_Type>::value || is_null_pointer<_Type>::value)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_scalar_v = is_not_scalar<_Type>::value;
#endif

/*
 *         _                  
 *      __| |___ __ __ _ _  _ 
 *     / _` / -_) _/ _` | || |
 *     \__,_\___\__\__,_|\_, |
 *                       |__/ 
 */

template <typename _Type>
struct decay
	: identity<conditional_t<
		has_extent<remove_reference_t<_Type>>::value,
		add_pointer_t<remove_extent_t<remove_reference_t<_Type>>>,
		conditional_t<
			is_function<remove_reference_t<_Type>>::value,
			add_pointer_t<remove_reference_t<_Type>>,
			remove_const_volatile_t<remove_reference_t<_Type>>>>> {};

template <typename _Type>
using decay_t = typename decay<_Type>::type;

template<typename _Type1, typename _Type2>
constexpr bool is_decay_equivalent = is_same<decay_t<_Type1>, _Type2>::value;

/*
 *      _                     _               _   _ _    _     
 *     (_)___  __ ___ _ _  __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< / _/ _ \ ' \(_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_\__\___/_||_/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|                                               
 */

template <typename _Type, typename... _Args>
struct is_constructible : boolean_constant<__is_constructible(_Type, _Args...)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type, typename... _Args>
	_EXTYPETRAITS_INLINE17 constexpr bool is_constructible_v = is_constructible<_Type, _Args...>::value;
#endif

/*
 *      _               _                    _               _   _ _    _     
 *     (_)___  _ _  ___| |_   __ ___ _ _  __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< | ' \/ _ \  _| / _/ _ \ ' \(_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_\__\___/_||_/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|          |___|                                               
 */

template <typename _Type, typename... _Args>
struct is_not_constructible : boolean_constant<!__is_constructible(_Type, _Args...)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type, typename... _Args>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_constructible_v = is_not_constructible<_Type, _Args...>::value;
#endif

/*
 *      _         _      __           _ _                    _               _   _ _    _     
 *     (_)___  __| |___ / _|__ _ _  _| | |_   __ ___ _ _  __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< / _` / -_)  _/ _` | || | |  _| / _/ _ \ ' \(_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_\__,_\___|_| \__,_|\_,_|_|\__|_\__\___/_||_/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|                          |___|                                               
 */

template <typename _Type>
struct is_default_constructible : boolean_constant<__is_constructible(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_default_constructible_v = is_default_constructible<_Type>::value;
#endif

/*
 *      _               _        _      __           _ _                    _               _   _ _    _     
 *     (_)___  _ _  ___| |_   __| |___ / _|__ _ _  _| | |_   __ ___ _ _  __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< | ' \/ _ \  _| / _` / -_)  _/ _` | || | |  _| / _/ _ \ ' \(_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_\__,_\___|_| \__,_|\_,_|_|\__|_\__\___/_||_/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|          |___|                          |___|                                               
 */

template <typename _Type>
struct is_not_default_constructible : boolean_constant<!__is_constructible(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_default_constructible_v = is_not_default_constructible<_Type>::value;
#endif

/*
 *      _               _   _                       _      __           _ _                    _               _   _ _    _     
 *     (_)___  _ _  ___| |_| |_  _ _ _____ __ __ __| |___ / _|__ _ _  _| | |_   __ ___ _ _  __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< | ' \/ _ \  _| ' \| '_/ _ \ V  V // _` / -_)  _/ _` | || | |  _| / _/ _ \ ' \(_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_||_|_| \___/\_/\_/_\__,_\___|_| \__,_|\_,_|_|\__|_\__\___/_||_/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|                             |___|                          |___|                                               
 */

template <typename _Type>
struct is_nothrow_default_constructible : boolean_constant<__is_nothrow_constructible(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_nothrow_default_constructible_v = is_nothrow_default_constructible<_Type>::value;
#endif

/*
 *      _               _              _   _                       _      __           _ _                    _               _   _ _    _     
 *     (_)___  _ _  ___| |_   _ _  ___| |_| |_  _ _ _____ __ __ __| |___ / _|__ _ _  _| | |_   __ ___ _ _  __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< | ' \/ _ \  _| | ' \/ _ \  _| ' \| '_/ _ \ V  V // _` / -_)  _/ _` | || | |  _| / _/ _ \ ' \(_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_|_||_\___/\__|_||_|_| \___/\_/\_/_\__,_\___|_| \__,_|\_,_|_|\__|_\__\___/_||_/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|          |___|                             |___|                          |___|                                               
 */

template <typename _Type>
struct is_not_nothrow_default_constructible : boolean_constant<!__is_nothrow_constructible(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_nothrow_default_constructible_v = is_not_nothrow_default_constructible<_Type>::value;
#endif

/*
 *      _     _       _     _      _ _                       _               _   _ _    _     
 *     (_)___| |_ _ _(_)_ _(_)__ _| | |_  _   __ ___ _ _  __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-<|  _| '_| \ V / / _` | | | || | / _/ _ \ ' \(_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_\__|_| |_|\_/|_\__,_|_|_|\_, |_\__\___/_||_/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|                       |__/___|                                               
 */

template <typename _Type, typename... _Args>
struct is_trivially_constructible : boolean_constant<__is_trivially_constructible(_Type, _Args...)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type, typename... _Args>
	_EXTYPETRAITS_INLINE17 constexpr bool is_trivially_constructible_v = is_trivially_constructible<_Type, _Args...>::value;
#endif

/*
 *      _               _    _       _     _      _ _                       _               _   _ _    _     
 *     (_)___  _ _  ___| |_ | |_ _ _(_)_ _(_)__ _| | |_  _   __ ___ _ _  __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< | ' \/ _ \  _||  _| '_| \ V / / _` | | | || | / _/ _ \ ' \(_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_\__|_| |_|\_/|_\__,_|_|_|\_, |_\__\___/_||_/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|          |___|                       |__/___|                                               
 */

template <typename _Type, typename... _Args>
struct is_not_trivially_constructible : boolean_constant<!__is_trivially_constructible(_Type, _Args...)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type, typename... _Args>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_trivially_constructible_v = is_not_trivially_constructible<_Type, _Args...>::value;
#endif

/*
 *      _     _       _     _      _ _           _      __           _ _                    _               _   _ _    _
 *     (_)___| |_ _ _(_)_ _(_)__ _| | |_  _   __| |___ / _|__ _ _  _| | |_   __ ___ _ _  __| |_ _ _ _  _ __| |_(_) |__| |___
 *     | (_-<|  _| '_| \ V / / _` | | | || | / _` / -_)  _/ _` | || | |  _| / _/ _ \ ' \(_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_\__|_| |_|\_/|_\__,_|_|_|\_, |_\__,_\___|_| \__,_|\_,_|_|\__|_\__\___/_||_/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|                       |__/___|                          |___|
 */

template <typename _Type>
struct is_trivially_default_constructible : boolean_constant<__is_trivially_constructible(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_trivially_default_constructible_v = is_trivially_constructible<_Type>::value;
#endif

/*
 *      _               _    _       _     _      _ _           _      __           _ _                    _               _   _ _    _     
 *     (_)___  _ _  ___| |_ | |_ _ _(_)_ _(_)__ _| | |_  _   __| |___ / _|__ _ _  _| | |_   __ ___ _ _  __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< | ' \/ _ \  _||  _| '_| \ V / / _` | | | || | / _` / -_)  _/ _` | || | |  _| / _/ _ \ ' \(_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_\__|_| |_|\_/|_\__,_|_|_|\_, |_\__,_\___|_| \__,_|\_,_|_|\__|_\__\___/_||_/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|          |___|                       |__/___|                          |___|                                               
 */
	
template <typename _Type>
struct is_not_trivially_default_constructible : boolean_constant<!__is_trivially_constructible(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_trivially_default_constructible_v = is_not_trivially_default_constructible<_Type>::value;
#endif

/*
 *      _               _   _                                   _               _   _ _    _     
 *     (_)___  _ _  ___| |_| |_  _ _ _____ __ __ __ ___ _ _  __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< | ' \/ _ \  _| ' \| '_/ _ \ V  V // _/ _ \ ' \(_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_||_|_| \___/\_/\_/_\__\___/_||_/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|                             |___|                                               
 */

template <typename _Type, typename... _Args>
struct is_nothrow_constructible : boolean_constant<__is_nothrow_constructible(_Type, _Args...)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type, typename... _Args>
	_EXTYPETRAITS_INLINE17 constexpr bool is_nothrow_constructible_v = is_nothrow_constructible<_Type, _Args...>::value;
#endif

/*
 *      _               _              _   _                                   _               _   _ _    _     
 *     (_)___  _ _  ___| |_   _ _  ___| |_| |_  _ _ _____ __ __ __ ___ _ _  __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< | ' \/ _ \  _| | ' \/ _ \  _| ' \| '_/ _ \ V  V // _/ _ \ ' \(_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_|_||_\___/\__|_||_|_| \___/\_/\_/_\__\___/_||_/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|          |___|                             |___|                                               
 */

template <typename _Type, typename... _Args>
struct is_not_nothrow_constructible : boolean_constant<!__is_nothrow_constructible(_Type, _Args...)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type, typename... _Args>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_nothrow_constructible_v = is_not_nothrow_constructible<_Type, _Args...>::value;
#endif

/*
 *      _                                        _               _   _ _    _     
 *     (_)___  __ ___ _ __ _  _   __ ___ _ _  __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< / _/ _ \ '_ \ || | / _/ _ \ ' \(_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_\__\___/ .__/\_, |_\__\___/_||_/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|     |_|   |__/___|                                               
 */

template <typename _Type>
struct is_copy_constructible : boolean_constant<__is_constructible(_Type, add_lvalue_reference_t<const _Type>)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_copy_constructible_v = is_copy_constructible<_Type>::value;
#endif

/*
 *      _               _                                       _               _   _ _    _     
 *     (_)___  _ _  ___| |_   __ ___ _ __ _  _   __ ___ _ _  __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< | ' \/ _ \  _| / _/ _ \ '_ \ || | / _/ _ \ ' \(_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_\__\___/ .__/\_, |_\__\___/_||_/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|          |___|     |_|   |__/___|                                               
 */

template <typename _Type>
struct is_not_copy_constructible : boolean_constant<!__is_constructible(_Type, add_lvalue_reference_t<const _Type>)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_copy_constructible_v = is_not_copy_constructible<_Type>::value;
#endif

/*
 *      _               _   _                                                      _               _   _ _    _     
 *     (_)___  _ _  ___| |_| |_  _ _ _____ __ __ __ ___ _ __ _  _   __ ___ _ _  __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< | ' \/ _ \  _| ' \| '_/ _ \ V  V // _/ _ \ '_ \ || | / _/ _ \ ' \(_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_||_|_| \___/\_/\_/_\__\___/ .__/\_, |_\__\___/_||_/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|                             |___|     |_|   |__/___|                                               
 */

template <typename _Type>
struct is_nothrow_copy_constructible 
	: boolean_constant<__is_nothrow_constructible(_Type, add_lvalue_reference_t<const _Type>)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_nothrow_copy_constructible_v = is_nothrow_copy_constructible<_Type>::value;
#endif

/*
 *      _               _              _   _                                                      _               _   _ _    _     
 *     (_)___  _ _  ___| |_   _ _  ___| |_| |_  _ _ _____ __ __ __ ___ _ __ _  _   __ ___ _ _  __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< | ' \/ _ \  _| | ' \/ _ \  _| ' \| '_/ _ \ V  V // _/ _ \ '_ \ || | / _/ _ \ ' \(_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_|_||_\___/\__|_||_|_| \___/\_/\_/_\__\___/ .__/\_, |_\__\___/_||_/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|          |___|                             |___|     |_|   |__/___|                                               
 */

template <typename _Type>
struct is_not_nothrow_copy_constructible 
	: boolean_constant<!__is_nothrow_constructible(_Type, add_lvalue_reference_t<const _Type>)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_nothrow_copy_constructible_v = is_not_nothrow_copy_constructible<_Type>::value;
#endif

/*
 *      _     _       _     _      _ _                                          _               _   _ _    _
 *     (_)___| |_ _ _(_)_ _(_)__ _| | |_  _   __ ___ _ __ _  _   __ ___ _ _  __| |_ _ _ _  _ __| |_(_) |__| |___
 *     | (_-<|  _| '_| \ V / / _` | | | || | / _/ _ \ '_ \ || | / _/ _ \ ' \(_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_\__|_| |_|\_/|_\__,_|_|_|\_, |_\__\___/ .__/\_, |_\__\___/_||_/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|                       |__/___|     |_|   |__/___|
 */

template <typename _Type>
struct is_trivially_copy_constructible 
	: boolean_constant<__is_trivially_constructible(_Type, add_lvalue_reference_t<const _Type>)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_trivially_copy_constructible_v = is_trivially_copy_constructible<_Type>::value;
#endif

/*
 *      _               _    _       _     _      _ _                                          _               _   _ _    _     
 *     (_)___  _ _  ___| |_ | |_ _ _(_)_ _(_)__ _| | |_  _   __ ___ _ __ _  _   __ ___ _ _  __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< | ' \/ _ \  _||  _| '_| \ V / / _` | | | || | / _/ _ \ '_ \ || | / _/ _ \ ' \(_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_\__|_| |_|\_/|_\__,_|_|_|\_, |_\__\___/ .__/\_, |_\__\___/_||_/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|          |___|                       |__/___|     |_|   |__/___|                                               
 */

template <typename _Type>
struct is_not_trivially_copy_constructible 
	: boolean_constant<!__is_trivially_constructible(_Type, add_lvalue_reference_t<const _Type>)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_trivially_copy_constructible_v = is_not_trivially_copy_constructible<_Type>::value;
#endif

/*
 *      _                                         _               _   _ _    _     
 *     (_)___  _ __  _____ _____   __ ___ _ _  __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< | '  \/ _ \ V / -_) / _/ _ \ ' \(_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_|_|_|_\___/\_/\___|_\__\___/_||_/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|               |___|                                               
 */

template <typename _Type>
struct is_move_constructible : boolean_constant<__is_constructible(_Type, _Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_move_constructible_v = is_move_constructible<_Type>::value;
#endif

/*
 *      _               _                                        _               _   _ _    _     
 *     (_)___  _ _  ___| |_   _ __  _____ _____   __ ___ _ _  __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< | ' \/ _ \  _| | '  \/ _ \ V / -_) / _/ _ \ ' \(_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_|_|_|_\___/\_/\___|_\__\___/_||_/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|          |___|               |___|                                               
 */

template <typename _Type>
struct is_not_move_constructible : boolean_constant<!__is_constructible(_Type, _Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_move_constructible_v = is_not_move_constructible<_Type>::value;
#endif

/*
 *      _               _   _                                                       _               _   _ _    _     
 *     (_)___  _ _  ___| |_| |_  _ _ _____ __ __ _ __  _____ _____   __ ___ _ _  __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< | ' \/ _ \  _| ' \| '_/ _ \ V  V /| '  \/ _ \ V / -_) / _/ _ \ ' \(_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_||_|_| \___/\_/\_/_|_|_|_\___/\_/\___|_\__\___/_||_/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|                             |___|               |___|                                               
 */

template <typename _Type>
struct is_nothrow_move_constructible : boolean_constant<__is_nothrow_constructible(_Type, _Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_nothrow_move_constructible_v = is_nothrow_move_constructible<_Type>::value;
#endif

/*
 *      _               _              _   _                                                       _               _   _ _    _     
 *     (_)___  _ _  ___| |_   _ _  ___| |_| |_  _ _ _____ __ __ _ __  _____ _____   __ ___ _ _  __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< | ' \/ _ \  _| | ' \/ _ \  _| ' \| '_/ _ \ V  V /| '  \/ _ \ V / -_) / _/ _ \ ' \(_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_|_||_\___/\__|_||_|_| \___/\_/\_/_|_|_|_\___/\_/\___|_\__\___/_||_/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|          |___|                             |___|               |___|                                               
 */

template <typename _Type>
struct is_not_nothrow_move_constructible : boolean_constant<!__is_nothrow_constructible(_Type, _Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_nothrow_move_constructible_v = is_not_nothrow_move_constructible<_Type>::value;
#endif

/*
 *      _     _       _     _      _ _                                           _               _   _ _    _     
 *     (_)___| |_ _ _(_)_ _(_)__ _| | |_  _   _ __  _____ _____   __ ___ _ _  __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-<|  _| '_| \ V / / _` | | | || | | '  \/ _ \ V / -_) / _/ _ \ ' \(_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_\__|_| |_|\_/|_\__,_|_|_|\_, |_|_|_|_\___/\_/\___|_\__\___/_||_/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|                       |__/___|               |___|                                               
 */

template <typename _Type>
struct is_trivially_move_constructible : boolean_constant<__is_trivially_constructible(_Type, _Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_trivially_move_constructible_v = is_trivially_move_constructible<_Type>::value;
#endif

/*
 *      _               _    _       _     _      _ _                                           _               _   _ _    _     
 *     (_)___  _ _  ___| |_ | |_ _ _(_)_ _(_)__ _| | |_  _   _ __  _____ _____   __ ___ _ _  __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< | ' \/ _ \  _||  _| '_| \ V / / _` | | | || | | '  \/ _ \ V / -_) / _/ _ \ ' \(_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_\__|_| |_|\_/|_\__,_|_|_|\_, |_|_|_|_\___/\_/\___|_\__\___/_||_/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|          |___|                       |__/___|               |___|                                               
 */

template <typename _Type>
struct is_not_trivially_move_constructible : boolean_constant<!__is_trivially_constructible(_Type, _Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_trivially_move_constructible_v = is_not_trivially_move_constructible<_Type>::value;
#endif

/*
 *      _                 _                _    _     
 *     (_)___  __ _ _____(_)__ _ _ _  __ _| |__| |___ 
 *     | (_-< / _` (_-<_-< / _` | ' \/ _` | '_ \ / -_)
 *     |_/__/_\__,_/__/__/_\__, |_||_\__,_|_.__/_\___|
 *         |___|           |___/                      
 */

template <typename _To, typename _From>
struct is_assignable : boolean_constant<__is_assignable(_To, _From)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _To, typename _From>
	_EXTYPETRAITS_INLINE17 constexpr bool is_assignable_v = is_assignable<_To, _From>::value;
#endif

/*
 *      _               _                _                _    _     
 *     (_)___  _ _  ___| |_   __ _ _____(_)__ _ _ _  __ _| |__| |___ 
 *     | (_-< | ' \/ _ \  _| / _` (_-<_-< / _` | ' \/ _` | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_\__,_/__/__/_\__, |_||_\__,_|_.__/_\___|
 *         |___|          |___|           |___/                      
 */

template <typename _To, typename _From>
struct is_not_assignable : boolean_constant<!__is_assignable(_To, _From)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _To, typename _From>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_assignable_v = is_not_assignable<_To, _From>::value;
#endif

/*
 *      _     _       _     _      _ _                   _                _    _     
 *     (_)___| |_ _ _(_)_ _(_)__ _| | |_  _   __ _ _____(_)__ _ _ _  __ _| |__| |___ 
 *     | (_-<|  _| '_| \ V / / _` | | | || | / _` (_-<_-< / _` | ' \/ _` | '_ \ / -_)
 *     |_/__/_\__|_| |_|\_/|_\__,_|_|_|\_, |_\__,_/__/__/_\__, |_||_\__,_|_.__/_\___|
 *         |___|                       |__/___|           |___/                      
 */

template <typename _To, typename _From>
struct is_trivially_assignable : boolean_constant<__is_trivially_assignable(_To, _From)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _To, typename _From>
	_EXTYPETRAITS_INLINE17 constexpr bool is_trivially_assignable_v = is_trivially_assignable<_To, _From>::value;
#endif

/*
 *      _               _    _       _     _      _ _                   _                _    _     
 *     (_)___  _ _  ___| |_ | |_ _ _(_)_ _(_)__ _| | |_  _   __ _ _____(_)__ _ _ _  __ _| |__| |___ 
 *     | (_-< | ' \/ _ \  _||  _| '_| \ V / / _` | | | || | / _` (_-<_-< / _` | ' \/ _` | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_\__|_| |_|\_/|_\__,_|_|_|\_, |_\__,_/__/__/_\__, |_||_\__,_|_.__/_\___|
 *         |___|          |___|                       |__/___|           |___/                      
 */

template <typename _To, typename _From>
struct is_not_trivially_assignable : boolean_constant<!__is_trivially_assignable(_To, _From)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _To, typename _From>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_trivially_assignable_v = is_not_trivially_assignable<_To, _From>::value;
#endif

/*
 *      _               _   _                               _                _    _     
 *     (_)___  _ _  ___| |_| |_  _ _ _____ __ __ __ _ _____(_)__ _ _ _  __ _| |__| |___ 
 *     | (_-< | ' \/ _ \  _| ' \| '_/ _ \ V  V // _` (_-<_-< / _` | ' \/ _` | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_||_|_| \___/\_/\_/_\__,_/__/__/_\__, |_||_\__,_|_.__/_\___|
 *         |___|                             |___|           |___/                      
 */

template <typename _To, typename _From>
struct is_nothrow_assignable : boolean_constant<__is_nothrow_assignable(_To, _From)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _To, typename _From>
	_EXTYPETRAITS_INLINE17 constexpr bool is_nothrow_assignable_v = is_nothrow_assignable<_To, _From>::value;
#endif

/*
 *      _               _              _   _                               _                _    _     
 *     (_)___  _ _  ___| |_   _ _  ___| |_| |_  _ _ _____ __ __ __ _ _____(_)__ _ _ _  __ _| |__| |___ 
 *     | (_-< | ' \/ _ \  _| | ' \/ _ \  _| ' \| '_/ _ \ V  V // _` (_-<_-< / _` | ' \/ _` | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_|_||_\___/\__|_||_|_| \___/\_/\_/_\__,_/__/__/_\__, |_||_\__,_|_.__/_\___|
 *         |___|          |___|                             |___|           |___/                      
 */

template <typename _To, typename _From>
struct is_not_nothrow_assignable : boolean_constant<!__is_nothrow_assignable(_To, _From)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _To, typename _From>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_nothrow_assignable_v = is_not_nothrow_assignable<_To, _From>::value;
#endif

/*
 *      _                                    _                _    _     
 *     (_)___  __ ___ _ __ _  _   __ _ _____(_)__ _ _ _  __ _| |__| |___ 
 *     | (_-< / _/ _ \ '_ \ || | / _` (_-<_-< / _` | ' \/ _` | '_ \ / -_)
 *     |_/__/_\__\___/ .__/\_, |_\__,_/__/__/_\__, |_||_\__,_|_.__/_\___|
 *         |___|     |_|   |__/___|           |___/                      
 */

template <typename _Type>
struct is_copy_assignable : boolean_constant<__is_assignable(add_lvalue_reference_t<_Type>, add_lvalue_reference_t<const _Type>)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_copy_assignable_v = is_copy_assignable<_Type>::value;
#endif

/*
 *      _               _                                   _                _    _     
 *     (_)___  _ _  ___| |_   __ ___ _ __ _  _   __ _ _____(_)__ _ _ _  __ _| |__| |___ 
 *     | (_-< | ' \/ _ \  _| / _/ _ \ '_ \ || | / _` (_-<_-< / _` | ' \/ _` | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_\__\___/ .__/\_, |_\__,_/__/__/_\__, |_||_\__,_|_.__/_\___|
 *         |___|          |___|     |_|   |__/___|           |___/                      
 */

template <typename _Type>
struct is_not_copy_assignable : boolean_constant<!__is_assignable(add_lvalue_reference_t<_Type>, add_lvalue_reference_t<const _Type>)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_copy_assignable_v = is_not_copy_assignable<_Type>::value;
#endif

/*
 *      _     _       _     _      _ _                                      _                _    _     
 *     (_)___| |_ _ _(_)_ _(_)__ _| | |_  _   __ ___ _ __ _  _   __ _ _____(_)__ _ _ _  __ _| |__| |___ 
 *     | (_-<|  _| '_| \ V / / _` | | | || | / _/ _ \ '_ \ || | / _` (_-<_-< / _` | ' \/ _` | '_ \ / -_)
 *     |_/__/_\__|_| |_|\_/|_\__,_|_|_|\_, |_\__\___/ .__/\_, |_\__,_/__/__/_\__, |_||_\__,_|_.__/_\___|
 *         |___|                       |__/___|     |_|   |__/___|           |___/                      
 */

template <typename _Type>
struct is_trivially_copy_assignable 
	: boolean_constant<__is_trivially_assignable(add_lvalue_reference_t<_Type>, add_lvalue_reference_t<const _Type>)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_trivially_copy_assignable_v = is_trivially_copy_assignable<_Type>::value;
#endif

/*
 *      _               _    _       _     _      _ _                                      _                _    _     
 *     (_)___  _ _  ___| |_ | |_ _ _(_)_ _(_)__ _| | |_  _   __ ___ _ __ _  _   __ _ _____(_)__ _ _ _  __ _| |__| |___ 
 *     | (_-< | ' \/ _ \  _||  _| '_| \ V / / _` | | | || | / _/ _ \ '_ \ || | / _` (_-<_-< / _` | ' \/ _` | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_\__|_| |_|\_/|_\__,_|_|_|\_, |_\__\___/ .__/\_, |_\__,_/__/__/_\__, |_||_\__,_|_.__/_\___|
 *         |___|          |___|                       |__/___|     |_|   |__/___|           |___/                      
 */

template <typename _Type>
struct is_not_trivially_copy_assignable 
	: boolean_constant<!__is_trivially_assignable(add_lvalue_reference_t<_Type>, add_lvalue_reference_t<const _Type>)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_trivially_copy_assignable_v = is_not_trivially_copy_assignable<_Type>::value;
#endif

/*
 *      _               _   _                                                  _                _    _     
 *     (_)___  _ _  ___| |_| |_  _ _ _____ __ __ __ ___ _ __ _  _   __ _ _____(_)__ _ _ _  __ _| |__| |___ 
 *     | (_-< | ' \/ _ \  _| ' \| '_/ _ \ V  V // _/ _ \ '_ \ || | / _` (_-<_-< / _` | ' \/ _` | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_||_|_| \___/\_/\_/_\__\___/ .__/\_, |_\__,_/__/__/_\__, |_||_\__,_|_.__/_\___|
 *         |___|                             |___|     |_|   |__/___|           |___/                      
 */

template <typename _Type>
struct is_nothrow_copy_assignable 
	: boolean_constant<__is_nothrow_assignable(add_lvalue_reference_t<_Type>, add_lvalue_reference_t<const _Type>)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_nothrow_copy_assignable_v = is_nothrow_copy_assignable<_Type>::value;
#endif

/*
 *      _               _              _   _                                                  _                _    _     
 *     (_)___  _ _  ___| |_   _ _  ___| |_| |_  _ _ _____ __ __ __ ___ _ __ _  _   __ _ _____(_)__ _ _ _  __ _| |__| |___ 
 *     | (_-< | ' \/ _ \  _| | ' \/ _ \  _| ' \| '_/ _ \ V  V // _/ _ \ '_ \ || | / _` (_-<_-< / _` | ' \/ _` | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_|_||_\___/\__|_||_|_| \___/\_/\_/_\__\___/ .__/\_, |_\__,_/__/__/_\__, |_||_\__,_|_.__/_\___|
 *         |___|          |___|                             |___|     |_|   |__/___|           |___/                      
 */

template <typename _Type>
struct is_not_nothrow_copy_assignable 
	: boolean_constant<!__is_nothrow_assignable(add_lvalue_reference_t<_Type>, add_lvalue_reference_t<const _Type>)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_nothrow_copy_assignable_v = is_not_nothrow_copy_assignable<_Type>::value;
#endif

/*
 *      _                                     _                _    _     
 *     (_)___  _ __  _____ _____   __ _ _____(_)__ _ _ _  __ _| |__| |___ 
 *     | (_-< | '  \/ _ \ V / -_) / _` (_-<_-< / _` | ' \/ _` | '_ \ / -_)
 *     |_/__/_|_|_|_\___/\_/\___|_\__,_/__/__/_\__, |_||_\__,_|_.__/_\___|
 *         |___|               |___|           |___/                      
 */

template <typename _Type>
struct is_move_assignable : boolean_constant<__is_assignable(add_lvalue_reference_t<_Type>, _Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_move_assignable_v = is_move_assignable<_Type>::value;
#endif

/*
 *      _               _                                    _                _    _     
 *     (_)___  _ _  ___| |_   _ __  _____ _____   __ _ _____(_)__ _ _ _  __ _| |__| |___ 
 *     | (_-< | ' \/ _ \  _| | '  \/ _ \ V / -_) / _` (_-<_-< / _` | ' \/ _` | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_|_|_|_\___/\_/\___|_\__,_/__/__/_\__, |_||_\__,_|_.__/_\___|
 *         |___|          |___|               |___|           |___/                      
 */

template <typename _Type>
struct is_not_move_assignable : boolean_constant<!__is_assignable(add_lvalue_reference_t<_Type>, _Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_move_assignable_v = is_not_move_assignable<_Type>::value;
#endif

/*
 *      _     _       _     _      _ _                                       _                _    _     
 *     (_)___| |_ _ _(_)_ _(_)__ _| | |_  _   _ __  _____ _____   __ _ _____(_)__ _ _ _  __ _| |__| |___ 
 *     | (_-<|  _| '_| \ V / / _` | | | || | | '  \/ _ \ V / -_) / _` (_-<_-< / _` | ' \/ _` | '_ \ / -_)
 *     |_/__/_\__|_| |_|\_/|_\__,_|_|_|\_, |_|_|_|_\___/\_/\___|_\__,_/__/__/_\__, |_||_\__,_|_.__/_\___|
 *         |___|                       |__/___|               |___|           |___/                      
 */

template <typename _Type>
struct is_trivially_move_assignable 
	: boolean_constant<__is_trivially_assignable(add_lvalue_reference_t<_Type>, _Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_trivially_move_assignable_v = is_trivially_move_assignable<_Type>::value;
#endif

/*
 *      _               _    _       _     _      _ _                                       _                _    _     
 *     (_)___  _ _  ___| |_ | |_ _ _(_)_ _(_)__ _| | |_  _   _ __  _____ _____   __ _ _____(_)__ _ _ _  __ _| |__| |___ 
 *     | (_-< | ' \/ _ \  _||  _| '_| \ V / / _` | | | || | | '  \/ _ \ V / -_) / _` (_-<_-< / _` | ' \/ _` | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_\__|_| |_|\_/|_\__,_|_|_|\_, |_|_|_|_\___/\_/\___|_\__,_/__/__/_\__, |_||_\__,_|_.__/_\___|
 *         |___|          |___|                       |__/___|               |___|           |___/                      
 */

template <typename _Type>
struct is_not_trivially_move_assignable 
	: boolean_constant<!__is_trivially_assignable(add_lvalue_reference_t<_Type>, _Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_trivially_move_assignable_v = is_not_trivially_move_assignable<_Type>::value;
#endif

/*
 *      _               _   _                                                   _                _    _     
 *     (_)___  _ _  ___| |_| |_  _ _ _____ __ __ _ __  _____ _____   __ _ _____(_)__ _ _ _  __ _| |__| |___ 
 *     | (_-< | ' \/ _ \  _| ' \| '_/ _ \ V  V /| '  \/ _ \ V / -_) / _` (_-<_-< / _` | ' \/ _` | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_||_|_| \___/\_/\_/_|_|_|_\___/\_/\___|_\__,_/__/__/_\__, |_||_\__,_|_.__/_\___|
 *         |___|                             |___|               |___|           |___/                      
 */

template <typename _Type>
struct is_nothrow_move_assignable 
	: boolean_constant<__is_nothrow_assignable(add_lvalue_reference_t<_Type>, _Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_nothrow_move_assignable_v = is_nothrow_move_assignable<_Type>::value;
#endif

/*
 *      _               _              _   _                                                   _                _    _     
 *     (_)___  _ _  ___| |_   _ _  ___| |_| |_  _ _ _____ __ __ _ __  _____ _____   __ _ _____(_)__ _ _ _  __ _| |__| |___ 
 *     | (_-< | ' \/ _ \  _| | ' \/ _ \  _| ' \| '_/ _ \ V  V /| '  \/ _ \ V / -_) / _` (_-<_-< / _` | ' \/ _` | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_|_||_\___/\__|_||_|_| \___/\_/\_/_|_|_|_\___/\_/\___|_\__,_/__/__/_\__, |_||_\__,_|_.__/_\___|
 *         |___|          |___|                             |___|               |___|           |___/                      
 */

template <typename _Type>
struct is_not_nothrow_move_assignable 
	: boolean_constant<!__is_nothrow_assignable(add_lvalue_reference_t<_Type>, _Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_nothrow_move_assignable_v = is_not_nothrow_move_assignable<_Type>::value;
#endif

/*
 *      _         _        _               _   _ _    _     
 *     (_)___  __| |___ __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< / _` / -_|_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_\__,_\___/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|                                            
 */

template <typename _Type>
struct is_destructible : boolean_constant<__is_destructible(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_destructible_v = is_destructible<_Type>::value;
#endif

/*
 *      _               _        _        _               _   _ _    _     
 *     (_)___  _ _  ___| |_   __| |___ __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< | ' \/ _ \  _| / _` / -_|_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_\__,_\___/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|          |___|                                            
 */

template <typename _Type>
struct is_not_destructible : boolean_constant<!__is_destructible(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_destructible_v = is_not_destructible<_Type>::value;
#endif

/*
 *      _     _       _     _      _ _           _        _               _   _ _    _     
 *     (_)___| |_ _ _(_)_ _(_)__ _| | |_  _   __| |___ __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-<|  _| '_| \ V / / _` | | | || | / _` / -_|_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_\__|_| |_|\_/|_\__,_|_|_|\_, |_\__,_\___/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|                       |__/___|                                            
 */

template <typename _Type>
struct is_trivially_destructible : boolean_constant<__is_trivially_destructible(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_trivially_destructible_v = is_trivially_destructible<_Type>::value;
#endif

/*
 *      _               _    _       _     _      _ _           _        _               _   _ _    _     
 *     (_)___  _ _  ___| |_ | |_ _ _(_)_ _(_)__ _| | |_  _   __| |___ __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< | ' \/ _ \  _||  _| '_| \ V / / _` | | | || | / _` / -_|_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_\__|_| |_|\_/|_\__,_|_|_|\_, |_\__,_\___/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|          |___|                       |__/___|                                            
 */

template <typename _Type>
struct is_not_trivially_destructible : boolean_constant<!__is_trivially_destructible(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_trivially_destructible_v = is_not_trivially_destructible<_Type>::value;
#endif

/*
 *      _               _   _                       _        _               _   _ _    _     
 *     (_)___  _ _  ___| |_| |_  _ _ _____ __ __ __| |___ __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< | ' \/ _ \  _| ' \| '_/ _ \ V  V // _` / -_|_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_||_|_| \___/\_/\_/_\__,_\___/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|                             |___|                                            
 */

template <typename _Type>
struct is_nothrow_destructible : boolean_constant<__is_nothrow_destructible(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_nothrow_destructible_v = is_nothrow_destructible<_Type>::value;
#endif

/*
 *      _               _              _   _                       _        _               _   _ _    _     
 *     (_)___  _ _  ___| |_   _ _  ___| |_| |_  _ _ _____ __ __ __| |___ __| |_ _ _ _  _ __| |_(_) |__| |___ 
 *     | (_-< | ' \/ _ \  _| | ' \/ _ \  _| ' \| '_/ _ \ V  V // _` / -_|_-<  _| '_| || / _|  _| | '_ \ / -_)
 *     |_/__/_|_||_\___/\__|_|_||_\___/\__|_||_|_| \___/\_/\_/_\__,_\___/__/\__|_|  \_,_\__|\__|_|_.__/_\___|
 *         |___|          |___|                             |___|                                            
 */

template <typename _Type>
struct is_not_nothrow_destructible : boolean_constant<!__is_nothrow_destructible(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_nothrow_destructible_v = is_not_nothrow_destructible<_Type>::value;
#endif

/*
 *      _                 _     _             _      _        _               _           
 *     | |_  __ _ _____ _(_)_ _| |_ _  _ __ _| |  __| |___ __| |_ _ _ _  _ __| |_ ___ _ _ 
 *     | ' \/ _` (_-<\ V / | '_|  _| || / _` | | / _` / -_|_-<  _| '_| || / _|  _/ _ \ '_|
 *     |_||_\__,_/__/_\_/|_|_|  \__|\_,_\__,_|_|_\__,_\___/__/\__|_|  \_,_\__|\__\___/_|  
 *                 |___|                      |___|                                       
 */

template <typename _Type>
struct has_virtual_destructor : boolean_constant<__has_virtual_destructor(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool has_virtual_destructor_v = has_virtual_destructor<_Type>::value;
#endif

/*
 *         _                        _     _                      _     _             _      _        _               _           
 *      __| |___  ___ ___  _ _  ___| |_  | |_  __ ___ _____ __ _(_)_ _| |_ _  _ __ _| |  __| |___ __| |_ _ _ _  _ __| |_ ___ _ _ 
 *     / _` / _ \/ -_|_-< | ' \/ _ \  _| | ' \/ _` \ V / -_)\ V / | '_|  _| || / _` | | / _` / -_|_-<  _| '_| || / _|  _/ _ \ '_|
 *     \__,_\___/\___/__/_|_||_\___/\__|_|_||_\__,_|\_/\___|_\_/|_|_|  \__|\_,_\__,_|_|_\__,_\___/__/\__|_|  \_,_\__|\__\___/_|  
 *                     |___|          |___|               |___|                      |___|                                       
 */

template <typename _Type>
struct does_not_have_virtual_destructor : boolean_constant<!__has_virtual_destructor(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool does_not_have_virtual_destructor_v = does_not_have_virtual_destructor<_Type>::value;
#endif

/*
 *      _                       _                     _     _        _                                      _        _   _             
 *     | |_  __ _ ___ _  _ _ _ (_)__ _ _  _ ___   ___| |__ (_)___ __| |_   _ _ ___ _ __ _ _ ___ ___ ___ _ _| |_ __ _| |_(_)___ _ _  ___
 *     | ' \/ _` (_-<| || | ' \| / _` | || / -_) / _ \ '_ \| / -_) _|  _| | '_/ -_) '_ \ '_/ -_|_-</ -_) ' \  _/ _` |  _| / _ \ ' \(_-<
 *     |_||_\__,_/__/_\_,_|_||_|_\__, |\_,_\___|_\___/_.__// \___\__|\__|_|_| \___| .__/_| \___/__/\___|_||_\__\__,_|\__|_\___/_||_/__/
 *                 |___|            |_|       |___|      |__/          |___|      |_|                                                  
 */

template <typename _Type>
struct has_unique_object_representations : boolean_constant<__has_unique_object_representations(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool has_unique_object_representations_v = has_unique_object_representations<_Type>::value;
#endif

/*
 *         _                        _     _                            _                     _     _        _                                      _        _   _             
 *      __| |___  ___ ___  _ _  ___| |_  | |_  __ ___ _____  _  _ _ _ (_)__ _ _  _ ___   ___| |__ (_)___ __| |_   _ _ ___ _ __ _ _ ___ ___ ___ _ _| |_ __ _| |_(_)___ _ _  ___
 *     / _` / _ \/ -_|_-< | ' \/ _ \  _| | ' \/ _` \ V / -_)| || | ' \| / _` | || / -_) / _ \ '_ \| / -_) _|  _| | '_/ -_) '_ \ '_/ -_|_-</ -_) ' \  _/ _` |  _| / _ \ ' \(_-<
 *     \__,_\___/\___/__/_|_||_\___/\__|_|_||_\__,_|\_/\___|_\_,_|_||_|_\__, |\_,_\___|_\___/_.__// \___\__|\__|_|_| \___| .__/_| \___/__/\___|_||_\__\__,_|\__|_\___/_||_/__/
 *                     |___|          |___|               |___|            |_|       |___|      |__/          |___|      |_|                                                  
 */

template <typename _Type>
struct does_not_have_unique_object_representations : boolean_constant<!__has_unique_object_representations(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool does_not_have_unique_object_representations_v = does_not_have_unique_object_representations<_Type>::value;
#endif

/*
 *      _           _       _               _   
 *     (_)___  __ _| |__ __| |_ _ _ __ _ __| |_ 
 *     | (_-< / _` | '_ (_-<  _| '_/ _` / _|  _|
 *     |_/__/_\__,_|_.__/__/\__|_| \__,_\__|\__|
 *         |___|                                
 */

template <typename _Type>
struct is_abstract : boolean_constant<__is_abstract(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_abstract_v = is_abstract<_Type>::value;
#endif

/*
 *      _               _          _       _               _   
 *     (_)___  _ _  ___| |_   __ _| |__ __| |_ _ _ __ _ __| |_ 
 *     | (_-< | ' \/ _ \  _| / _` | '_ (_-<  _| '_/ _` / _|  _|
 *     |_/__/_|_||_\___/\__|_\__,_|_.__/__/\__|_| \__,_\__|\__|
 *         |___|          |___|                                
 */

template <typename _Type>
struct is_not_abstract : boolean_constant<!__is_abstract(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_abstract_v = is_not_abstract<_Type>::value;
#endif

/*
 *      _       __ _           _ 
 *     (_)___  / _(_)_ _  __ _| |
 *     | (_-< |  _| | ' \/ _` | |
 *     |_/__/_|_| |_|_||_\__,_|_|
 *         |___|                 
 */

template <typename _Type>
struct is_final : boolean_constant<__is_final(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_final_v = is_final<_Type>::value;
#endif

/*
 *      _               _      __ _           _ 
 *     (_)___  _ _  ___| |_   / _(_)_ _  __ _| |
 *     | (_-< | ' \/ _ \  _| |  _| | ' \/ _` | |
 *     |_/__/_|_||_\___/\__|_|_| |_|_||_\__,_|_|
 *         |___|          |___|                 
 */

template <typename _Type>
struct is_not_final : boolean_constant<!__is_final(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_final_v = is_not_final<_Type>::value;
#endif

/*
 *      _                     _        
 *     (_)___  ___ _ __  _ __| |_ _  _ 
 *     | (_-< / -_) '  \| '_ \  _| || |
 *     |_/__/_\___|_|_|_| .__/\__|\_, |
 *         |___|        |_|       |__/ 
 */

template <typename _Type>
struct is_empty : boolean_constant<__is_empty(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_empty_v = is_empty<_Type>::value;
#endif 

/*
 *      _               _                    _        
 *     (_)___  _ _  ___| |_   ___ _ __  _ __| |_ _  _ 
 *     | (_-< | ' \/ _ \  _| / -_) '  \| '_ \  _| || |
 *     |_/__/_|_||_\___/\__|_\___|_|_|_| .__/\__|\_, |
 *         |___|          |___|        |_|       |__/ 
 */

template <typename _Type>
struct is_not_empty : boolean_constant<!__is_empty(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_empty_v = is_not_empty<_Type>::value;
#endif 

/*
 *      _                                       _       
 *     (_)___  __ _ __ _ __ _ _ _ ___ __ _ __ _| |_ ___ 
 *     | (_-< / _` / _` / _` | '_/ -_) _` / _` |  _/ -_)
 *     |_/__/_\__,_\__, \__, |_| \___\__, \__,_|\__\___|
 *         |___|   |___/|___/        |___/              
 */

template <typename _Type>
struct is_aggregate : boolean_constant<__is_aggregate(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_aggregate_v = is_aggregate<_Type>::value;
#endif 

/*
 *      _               _                                      _       
 *     (_)___  _ _  ___| |_   __ _ __ _ __ _ _ _ ___ __ _ __ _| |_ ___ 
 *     | (_-< | ' \/ _ \  _| / _` / _` / _` | '_/ -_) _` / _` |  _/ -_)
 *     |_/__/_|_||_\___/\__|_\__,_\__, \__, |_| \___\__, \__,_|\__\___|
 *         |___|          |___|   |___/|___/        |___/              
 */

template <typename _Type>
struct is_not_aggregate : boolean_constant<!__is_aggregate(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_aggregate_v = is_not_aggregate<_Type>::value;
#endif 

/*
 *      _         _            
 *     (_)___  __| |__ _ ______
 *     | (_-< / _| / _` (_-<_-<
 *     |_/__/_\__|_\__,_/__/__/
 *         |___|               
 */

template <typename _Type>
struct is_class : boolean_constant<__is_class(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_class_v = is_class<_Type>::value;
#endif 

/*
 *      _               _        _            
 *     (_)___  _ _  ___| |_   __| |__ _ ______
 *     | (_-< | ' \/ _ \  _| / _| / _` (_-<_-<
 *     |_/__/_|_||_\___/\__|_\__|_\__,_/__/__/
 *         |___|          |___|               
 */

template <typename _Type>
struct is_not_class : boolean_constant<!__is_class(_Type)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_class_v = is_not_class<_Type>::value;
#endif 

/*
 *      _      _                         __ 
 *     (_)___ | |__  __ _ ___ ___   ___ / _|
 *     | (_-< | '_ \/ _` (_-</ -_) / _ \  _|
 *     |_/__/_|_.__/\__,_/__/\___|_\___/_|  
 *         |___|                |___|       
 */

template <typename _Base, typename _Derived>
struct is_base_of : boolean_constant<__is_base_of(_Base, _Derived)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Base, typename _Derived>
	_EXTYPETRAITS_INLINE17 constexpr bool is_base_of_v = is_base_of<_Base, _Derived>::value;
#endif 

/*
 *      _               _     _                         __ 
 *     (_)___  _ _  ___| |_  | |__  __ _ ___ ___   ___ / _|
 *     | (_-< | ' \/ _ \  _| | '_ \/ _` (_-</ -_) / _ \  _|
 *     |_/__/_|_||_\___/\__|_|_.__/\__,_/__/\___|_\___/_|  
 *         |___|          |___|                |___|       
 */

template <typename _Base, typename _Derived>
struct is_not_base_of : boolean_constant<!__is_base_of(_Base, _Derived)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Base, typename _Derived>
	_EXTYPETRAITS_INLINE17 constexpr bool is_not_base_of_v = is_not_base_of<_Base, _Derived>::value;
#endif 

/*
 *      _                 _     _           _     _                                  _   _ _    _       _                         __ 
 *     (_)___   _ __  ___(_)_ _| |_ ___ _ _(_)_ _| |_ ___ _ _ __ ___ _ ___ _____ _ _| |_(_) |__| |___  | |__  __ _ ___ ___   ___ / _|
 *     | (_-<  | '_ \/ _ \ | ' \  _/ -_) '_| | ' \  _/ -_) '_/ _/ _ \ ' \ V / -_) '_|  _| | '_ \ / -_) | '_ \/ _` (_-</ -_) / _ \  _|
 *     |_/__/__| .__/\___/_|_||_\__\___|_|_|_|_||_\__\___|_| \__\___/_||_\_/\___|_|  \__|_|_.__/_\___|_|_.__/\__,_/__/\___|_\___/_|  
 *         |___|_|                      |___|                                                       |___|                |___|       
 */

template <typename _Base, typename _Derived>
struct is_pointer_interconvertible_base_of : boolean_constant<__is_pointer_interconvertible_base_of(_Base, _Derived)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Base, typename _Derived>
	_EXTYPETRAITS_INLINE17 constexpr bool is_pointer_interconvertible_base_of_v = is_pointer_interconvertible_base_of<_Base, _Derived>::value;
#endif 

/*
 *      _                 _     _                    _     _     _                                  _   _ _    _       _                         __ 
 *     (_)___   _ __  ___(_)_ _| |_ ___ _ _ _ _  ___| |_  (_)_ _| |_ ___ _ _ __ ___ _ ___ _____ _ _| |_(_) |__| |___  | |__  __ _ ___ ___   ___ / _|
 *     | (_-<  | '_ \/ _ \ | ' \  _/ -_) '_| ' \/ _ \  _| | | ' \  _/ -_) '_/ _/ _ \ ' \ V / -_) '_|  _| | '_ \ / -_) | '_ \/ _` (_-</ -_) / _ \  _|
 *     |_/__/__| .__/\___/_|_||_\__\___|_|_|_||_\___/\__|_|_|_||_\__\___|_| \__\___/_||_\_/\___|_|  \__|_|_.__/_\___|_|_.__/\__,_/__/\___|_\___/_|  
 *         |___|_|                      |___|          |___|                                                       |___|                |___|       
 */

template <typename _Base, typename _Derived>
struct is_pointer_not_interconvertible_base_of : boolean_constant<!__is_pointer_interconvertible_base_of(_Base, _Derived)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Base, typename _Derived>
	_EXTYPETRAITS_INLINE17 constexpr bool is_pointer_not_interconvertible_base_of_v = is_pointer_not_interconvertible_base_of<_Base, _Derived>::value;
#endif 

/*
 *      _      _                    _                             _   _ _    _     
 *     (_)___ | |__ _ _  _ ___ _  _| |_   __ ___ _ __  _ __  __ _| |_(_) |__| |___ 
 *     | (_-< | / _` | || / _ \ || |  _| / _/ _ \ '  \| '_ \/ _` |  _| | '_ \ / -_)
 *     |_/__/_|_\__,_|\_, \___/\_,_|\__|_\__\___/_|_|_| .__/\__,_|\__|_|_.__/_\___|
 *         |___|      |__/            |___|           |_|                          
 */

template <typename _Type1, typename _Type2>
struct is_layout_compatible : boolean_constant<__is_layout_compatible(_Type1, _Type2)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type1, typename _Type2>
	_EXTYPETRAITS_INLINE17 constexpr bool is_layout_compatible_v = is_layout_compatible<_Type1, _Type2>::value;
#endif 

/*
 *      _      _                    _     _                              _   _ _    _     
 *     (_)___ | |__ _ _  _ ___ _  _| |_  (_)_ _  __ ___ _ __  _ __  __ _| |_(_) |__| |___ 
 *     | (_-< | / _` | || / _ \ || |  _| | | ' \/ _/ _ \ '  \| '_ \/ _` |  _| | '_ \ / -_)
 *     |_/__/_|_\__,_|\_, \___/\_,_|\__|_|_|_||_\__\___/_|_|_| .__/\__,_|\__|_|_.__/_\___|
 *         |___|      |__/            |___|                  |_|                          
 */

template <typename _Type1, typename _Type2>
struct is_layout_incompatible : boolean_constant<!__is_layout_compatible(_Type1, _Type2)> {};

#if _EXTYPETRAITS_HAS_CXX14
	template <typename _Type1, typename _Type2>
	_EXTYPETRAITS_INLINE17 constexpr bool is_layout_incompatible_v = is_layout_incompatible<_Type1, _Type2>::value;
#endif 

/*
 *                                                             _ _               __              _        __    __ _ _     
 *      _ _  __ _ _ __  ___ ____ __  __ _ __ ___   ___ _ _  __| (_)_ _  __ _    / /  ___ _ _  __| |  ___ / _|  / _(_) |___ 
 *     | ' \/ _` | '  \/ -_|_-< '_ \/ _` / _/ -_) / -_) ' \/ _` | | ' \/ _` |  / /  / -_) ' \/ _` | / _ \  _| |  _| | / -_)
 *     |_||_\__,_|_|_|_\___/__/ .__/\__,_\__\___| \___|_||_\__,_|_|_||_\__, | /_/   \___|_||_\__,_| \___/_|   |_| |_|_\___|
 *                            |_|                                      |___/                                               
 */

}

#endif
