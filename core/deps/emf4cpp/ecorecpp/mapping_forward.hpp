// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * mapping_forward.hpp
 * Copyright (C) Cátedra SAES-UMU 2010 <andres.senac@um.es>
 *
 * EMF4CPP is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EMF4CPP is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ECORECPP_MAPPING_FORWARD_HPP
#define    ECORECPP_MAPPING_FORWARD_HPP

#include <memory>
#include <ctime>
#include <list>
#include <vector>

#include "mapping/type_traits.hpp"
#include "mapping/any.hpp"
#include "mapping/out_ptr.hpp"

namespace ecorecpp
{
namespace mapping
{

template< typename T >
class out_ptr;

template< typename T >
struct any_traits;

template< typename T >
struct string_traits;

template< typename T >
struct set_traits;

template< typename T >
class EList;

template< typename T, typename Q >
class DelegateEList;

} // mapping
} // ecorecpp

#endif // ECORECPP_MAPPING_FORWARD_HPP
