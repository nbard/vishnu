// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * IMS_Data/MetricImpl.cpp
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

#include "Metric.hpp"
#include <IMS_Data/IMS_DataPackage.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::IMS_Data;

/*PROTECTED REGION ID(MetricImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void Metric::_initialize()
{
    // Supertypes

    // Rerefences

    /*PROTECTED REGION ID(MetricImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject Metric::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean _resolve)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::IMS_Data::IMS_DataPackage::METRIC__TYPE:
    {
        ::ecorecpp::mapping::any_traits< ::IMS_Data::MetricType >::toAny(_any,
                m_type);
    }
        return _any;
    case ::IMS_Data::IMS_DataPackage::METRIC__VALUE:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EDouble >::toAny(_any,
                m_value);
    }
        return _any;
    case ::IMS_Data::IMS_DataPackage::METRIC__TIME:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EInt >::toAny(_any, m_time);
    }
        return _any;

    }
    throw "Error";
}

void Metric::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const& _newValue)
{
    switch (_featureID)
    {
    case ::IMS_Data::IMS_DataPackage::METRIC__TYPE:
    {
        ::ecorecpp::mapping::any_traits< ::IMS_Data::MetricType >::fromAny(
                _newValue, m_type);
    }
        return;
    case ::IMS_Data::IMS_DataPackage::METRIC__VALUE:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EDouble >::fromAny(_newValue,
                m_value);
    }
        return;
    case ::IMS_Data::IMS_DataPackage::METRIC__TIME:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EInt >::fromAny(_newValue,
                m_time);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean Metric::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::IMS_Data::IMS_DataPackage::METRIC__TYPE:
        return ::ecorecpp::mapping::set_traits< ::IMS_Data::MetricType >::is_set(
                m_type);
    case ::IMS_Data::IMS_DataPackage::METRIC__VALUE:
        return ::ecorecpp::mapping::set_traits< ::ecore::EDouble >::is_set(
                m_value);
    case ::IMS_Data::IMS_DataPackage::METRIC__TIME:
        return ::ecorecpp::mapping::set_traits< ::ecore::EInt >::is_set(m_time);

    }
    throw "Error";
}

void Metric::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr Metric::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::IMS_Data::IMS_DataPackage_ptr > (::IMS_Data::IMS_DataPackage::_instance())->getMetric();
    return _eclass;
}

