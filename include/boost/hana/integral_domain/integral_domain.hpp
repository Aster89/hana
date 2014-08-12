/*!
@file
Forward declares `boost::hana::IntegralDomain`.

@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_INTEGRAL_DOMAIN_INTEGRAL_DOMAIN_HPP
#define BOOST_HANA_INTEGRAL_DOMAIN_INTEGRAL_DOMAIN_HPP

#include <boost/hana/core/datatype.hpp>
#include <boost/hana/core/typeclass.hpp>
#include <boost/hana/detail/constexpr.hpp>
#include <boost/hana/detail/std/forward.hpp>


namespace boost { namespace hana {
    //! @ingroup group-typeclasses
    //! `IntegralDomain`s are commutative `Ring`s with only `zero` as a
    //! zero divisor.
    //!
    //! Typical examples of `IntegralDomain` include integers and polynomials
    //! over a field. The method names refer to the integral domain of
    //! integers under addition and multiplication.
    //!
    //! ### Requires
    //! `Ring`
    //!
    //! ### Laws
    //! For all objects `a`, `b` and `k` of an `IntegralDomain` `D`, the
    //! following laws must be satisfied:
    //! @code
    //!     mult(a, b) == mult(b, a)                                  // commutativity
    //!     plus(mult(quot(a, b), b), mod(a, b)) == a if b is non-zero
    //!     mod(plus(a, mult(k, b)), b) == mod(a, b)  if b is non-zero // canonicity
    //!     mod(zero<D>, b) == zero<D>                if b is non-zero
    //! @endcode
    struct IntegralDomain {
        BOOST_HANA_BINARY_TYPECLASS(IntegralDomain);
        struct mcd;
    };

    //! Generalized integer remainder.
    //! @relates IntegralDomain
    //!
    //! Specifically, `mod(a, b)` picks a canonical element of the equivalence
    //! class of `a` in the ideal generated by `b`.
    //!
    //! ### Example
    //! @snippet example/integral_domain.cpp mod
    BOOST_HANA_CONSTEXPR_LAMBDA auto mod = [](auto&& a, auto&& b) -> decltype(auto) {
        return IntegralDomain::instance<
            datatype_t<decltype(a)>, datatype_t<decltype(b)>
        >::mod_impl(
            detail::std::forward<decltype(a)>(a),
            detail::std::forward<decltype(b)>(b)
        );
    };

    //! Generalized integer quotient.
    //! @relates IntegralDomain
    //!
    //! ### Example
    //! @snippet example/integral_domain.cpp quot
    BOOST_HANA_CONSTEXPR_LAMBDA auto quot = [](auto&& a, auto&& b) -> decltype(auto) {
        return IntegralDomain::instance<
            datatype_t<decltype(a)>, datatype_t<decltype(b)>
        >::quot_impl(
            detail::std::forward<decltype(a)>(a),
            detail::std::forward<decltype(b)>(b)
        );
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_INTEGRAL_DOMAIN_INTEGRAL_DOMAIN_HPP
