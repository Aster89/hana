/*!
@file
Forward declares `boost::hana::StdPair`.

@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_EXT_STD_PAIR_PAIR_HPP
#define BOOST_HANA_EXT_STD_PAIR_PAIR_HPP

#include <boost/hana/core/datatype.hpp>

#include <utility>


namespace boost { namespace hana {
    struct StdPair;

    template <typename First, typename Second>
    struct datatype<std::pair<First, Second>> {
        using type = StdPair;
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_EXT_STD_PAIR_PAIR_HPP
