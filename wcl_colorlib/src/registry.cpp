#include "precompiled_header.hpp"

// wcl_colorlib - portable color library
// Copyright (C) <2007>  Wei Hu <wei.hu.tw@gmail.com>
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#include "..\..\wcl_registry\include\registry.hpp"
#include "registry.hpp"

namespace Wcl
{
  namespace Colorlib
  {
#if defined(WCL_COLORLIB_USE_REGISTRY)
    Registry::key_t REGISTRY_PARENT_KEY = HKEY_LOCAL_MACHINE;
    wchar_t const *REGISTRY_KEY_NAME = L"SOFTWARE\\WeiCommonLib";
#endif
  }
}
