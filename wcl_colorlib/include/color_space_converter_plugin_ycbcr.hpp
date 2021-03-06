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

#ifndef __wcl_colorlib_color_space_converter_plugin_YCbCr_hpp__
#define __wcl_colorlib_color_space_converter_plugin_YCbCr_hpp__

#include "export.hpp"
#include "color_space_converter_plugin.hpp"
#include "color_space_converter_plugin_ypbpr.hpp"
#include "converter.hpp"

namespace Wcl
{
  namespace Colorlib
  {
    class ColorSpaceConverterPluginYCbCr : public virtual ColorSpaceConverterPluginYPbPr
    {
    private:
      
      uint32_t m_ycbcr_plugin_id;
      
      uint8_t m_y_multiplier,  m_y_addend;
      uint8_t m_cb_multiplier, m_cb_addend;
      uint8_t m_cr_multiplier, m_cr_addend;
      
      WCL_COLORLIB_EXPORT virtual void convert_from_YPbPr_to_YCbCr(
        std::vector<ColorSpaceBasicUnitValue> const &ypbpr_data,
        std::vector<ColorSpaceBasicUnitValue> &ycbcr_data);
      
      WCL_COLORLIB_EXPORT virtual void convert_from_YCbCr_to_YPbPr(
        std::vector<ColorSpaceBasicUnitValue> const &ycbcr_data,
        std::vector<ColorSpaceBasicUnitValue> &ypbpr_data);
      
      virtual wchar_t const *get_ycbcr_plugin_name() const = 0;
      virtual void get_ycbcr_plugin_parent_name_list(wchar_t const ***parent_name_list, uint32_t *parent_name_list_size) const = 0;
      
      uint32_t get_ycbcr_plugin_id() const
      { return m_ycbcr_plugin_id; }
      
    protected:
      
      /** @name life cycle
       */
      //@{
      /**
       * Because class derived from this class should treat
       * this class as its virtual base class. So that I
       * have to provide a default constructor, then derived
       * classes would not initialize this class
       * explicitly.
       */
      ColorSpaceConverterPluginYCbCr()
        : COLOR_SPACE_CONVERTER_PLUGIN_SET_CONVERTER(0),
          m_ycbcr_plugin_id(0)
      {}
      
      virtual ~ColorSpaceConverterPluginYCbCr() {}
      //@}
      
      WCL_COLORLIB_EXPORT void set_ycbcr_plugin_id();
      
      WCL_COLORLIB_EXPORT void set_ycbcr_quantization_level(
        uint8_t const y_multiplier, uint8_t const y_addend,
        uint8_t const cb_multiplier, uint8_t const cb_addend,
        uint8_t const cr_multiplier, uint8_t const cr_addend);
      
    public:
      
      /** @name Conversion
       */
      //@{
      WCL_COLORLIB_EXPORT virtual bool convert_to_cie1931_XYZ(
        std::vector<ColorSpaceBasicUnitValue> const &src_data,
        std::vector<ColorSpaceBasicUnitValue> &dst_data,
        uint32_t const dst_plugin_id);
      
      WCL_COLORLIB_EXPORT virtual void convert_from_cie1931_XYZ(
        std::vector<ColorSpaceBasicUnitValue> const &src_data,
        std::vector<ColorSpaceBasicUnitValue> &dst_data,
        uint32_t const src_plugin_id);
      //@}
      
      /** @name Querying
       */
      //@{
      WCL_COLORLIB_EXPORT virtual void get_input_data_range(
        uint32_t const idx,
        std::vector<std::pair<ColorSpaceBasicUnitValue, ColorSpaceBasicUnitValue> > &ranges) const;
      
      WCL_COLORLIB_EXPORT virtual uint32_t get_subcomponent_count() const;
      
      WCL_COLORLIB_EXPORT virtual ColorSpaceBasicUnitValueType get_basic_unit_value_type() const;
      //@}
      
      /** @name Checking
       */
      //@{
      WCL_COLORLIB_EXPORT virtual void check_valid_input_idx(
        uint32_t const idx) const;
      
      WCL_COLORLIB_EXPORT virtual void check_valid_input_value(
        uint32_t const idx,
        ColorSpaceBasicUnitValue const &value) const;
      //@}
    };
    typedef class ColorSpaceConverterPluginRgb ColorSpaceConverterPluginRgb;
  }
}

#endif
