// Copyright David Abrahams 2002. Permission to copy, use,
// modify, sell and distribute this software is granted provided this
// copyright notice appears in all copies. This software is provided
// "as is" without express or implied warranty, and with no claim as
// to its suitability for any purpose.
#ifndef PREPROCESSOR_DWA200247_HPP
# define PREPROCESSOR_DWA200247_HPP

# include <boost/preprocessor/cat.hpp>
# include <boost/preprocessor/comma_if.hpp>
# include <boost/preprocessor/repeat.hpp>
# include <boost/preprocessor/tuple/elem.hpp>

// stuff that should be in the preprocessor library

# define BOOST_PYTHON_APPLY(x) BOOST_PP_CAT(BOOST_PYTHON_APPLY_, x)

# define BOOST_PYTHON_APPLY_BOOST_PYTHON_ITEM(v) v
# define BOOST_PYTHON_APPLY_BOOST_PYTHON_NIL

// cv-qualifiers

# if !defined(__MWERKS__) || __MWERKS__ > 0x2407
#  define BOOST_PYTHON_CV_COUNT 4
# else
#  define BOOST_PYTHON_CV_COUNT 1
# endif

# ifndef BOOST_PYTHON_MAX_ARITY
#  define BOOST_PYTHON_MAX_ARITY 15
# endif

# define BOOST_PYTHON_CV_QUALIFIER(i)                          \
    BOOST_PYTHON_APPLY(                                        \
        BOOST_PP_TUPLE_ELEM(4, i, BOOST_PYTHON_CV_QUALIFIER_I) \
    )

# define BOOST_PYTHON_CV_QUALIFIER_I      \
    (                                     \
        BOOST_PYTHON_NIL,                 \
        BOOST_PYTHON_ITEM(const),         \
        BOOST_PYTHON_ITEM(volatile),      \
        BOOST_PYTHON_ITEM(const volatile) \
    )

// enumerators
# define BOOST_PYTHON_UNARY_ENUM(c, text) BOOST_PP_REPEAT(c, BOOST_PYTHON_UNARY_ENUM_I, text)
# define BOOST_PYTHON_UNARY_ENUM_I(n, text) BOOST_PP_COMMA_IF(n) text ## n

# define BOOST_PYTHON_BINARY_ENUM(c, a, b) BOOST_PP_REPEAT(c, BOOST_PYTHON_BINARY_ENUM_I, (a, b))
# define BOOST_PYTHON_BINARY_ENUM_I(n, _) BOOST_PP_COMMA_IF(n) BOOST_PP_CAT(BOOST_PP_TUPLE_ELEM(2, 0, _), n) BOOST_PP_CAT(BOOST_PP_TUPLE_ELEM(2, 1, _), n)

# define BOOST_PYTHON_ENUM_WITH_DEFAULT(c, text, def) BOOST_PP_REPEAT(c, BOOST_PYTHON_ENUM_WITH_DEFAULT_I, (text, def))
# define BOOST_PYTHON_ENUM_WITH_DEFAULT_I(n, _) BOOST_PP_COMMA_IF(n) BOOST_PP_CAT(BOOST_PP_TUPLE_ELEM(2, 0, _), n) = BOOST_PP_TUPLE_ELEM(2, 1, _)

// fixed text (no commas)
# define BOOST_PYTHON_FIXED(n, text) text

// flags
# define BOOST_PYTHON_FUNCTION_POINTER 0x0001
# define BOOST_PYTHON_POINTER_TO_MEMBER 0x0002

#endif // PREPROCESSOR_DWA200247_HPP
