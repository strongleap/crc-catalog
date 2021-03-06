///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2000 - 2018.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>

#include <crc_catalog_c.h>

namespace
{
  template<typename UnsignedIntegralTypeResult,
           typename UnsignedIntegralTypeControl>
  bool crc_check(      UnsignedIntegralTypeResult(*crc_function)(const std::uint8_t*, const std::size_t),
                 const UnsignedIntegralTypeControl& crc_control)
  {
    using value_type = UnsignedIntegralTypeResult;

    const std::array<std::uint8_t, 9U> crc_test_data =
    {{
      0x31U, 0x32U, 0x33U, 0x34U, 0x35U, 0x36U, 0x37U, 0x38U, 0x39U
    }};

    const value_type crc_result =
      crc_function(crc_test_data.data(), crc_test_data.size());

    const bool crc_result_is_ok = (crc_result == UnsignedIntegralTypeResult(crc_control));

    return crc_result_is_ok;
  }
} // anonymous namespace

int main()
{
  bool crc_result_is_ok = true;

  crc_result_is_ok &= crc_check(crc_crc03_gsm         , UINTMAX_C(0x0000000000000004));
  crc_result_is_ok &= crc_check(crc_crc03_rohc        , UINTMAX_C(0x0000000000000006));
  crc_result_is_ok &= crc_check(crc_crc04_interlaken  , UINTMAX_C(0x000000000000000B));
  crc_result_is_ok &= crc_check(crc_crc04_itu         , UINTMAX_C(0x0000000000000007));
  crc_result_is_ok &= crc_check(crc_crc05_epc         , UINTMAX_C(0x0000000000000000));
  crc_result_is_ok &= crc_check(crc_crc05_itu         , UINTMAX_C(0x0000000000000007));
  crc_result_is_ok &= crc_check(crc_crc05_usb         , UINTMAX_C(0x0000000000000019));
  crc_result_is_ok &= crc_check(crc_crc06_cdma2000_a  , UINTMAX_C(0x000000000000000D));
  crc_result_is_ok &= crc_check(crc_crc06_cdma2000_b  , UINTMAX_C(0x000000000000003B));
  crc_result_is_ok &= crc_check(crc_crc06_darc        , UINTMAX_C(0x0000000000000026));
  crc_result_is_ok &= crc_check(crc_crc06_gsm         , UINTMAX_C(0x0000000000000013));
  crc_result_is_ok &= crc_check(crc_crc06_itu         , UINTMAX_C(0x0000000000000006));
  crc_result_is_ok &= crc_check(crc_crc07             , UINTMAX_C(0x0000000000000075));
  crc_result_is_ok &= crc_check(crc_crc07_rohc        , UINTMAX_C(0x0000000000000053));
  crc_result_is_ok &= crc_check(crc_crc07_umts        , UINTMAX_C(0x0000000000000061));
  crc_result_is_ok &= crc_check(crc_crc08             , UINTMAX_C(0x00000000000000F4));
  crc_result_is_ok &= crc_check(crc_crc08_autosar     , UINTMAX_C(0x00000000000000DF));
  crc_result_is_ok &= crc_check(crc_crc08_bluetooth   , UINTMAX_C(0x0000000000000026));
  crc_result_is_ok &= crc_check(crc_crc08_cdma2000    , UINTMAX_C(0x00000000000000DA));
  crc_result_is_ok &= crc_check(crc_crc08_darc        , UINTMAX_C(0x0000000000000015));
  crc_result_is_ok &= crc_check(crc_crc08_dvb_s2      , UINTMAX_C(0x00000000000000BC));
  crc_result_is_ok &= crc_check(crc_crc08_ebu         , UINTMAX_C(0x0000000000000097));
  crc_result_is_ok &= crc_check(crc_crc08_gsm_a       , UINTMAX_C(0x0000000000000037));
  crc_result_is_ok &= crc_check(crc_crc08_gsm_b       , UINTMAX_C(0x0000000000000094));
  crc_result_is_ok &= crc_check(crc_crc08_i_code      , UINTMAX_C(0x000000000000007E));
  crc_result_is_ok &= crc_check(crc_crc08_itu         , UINTMAX_C(0x00000000000000A1));
  crc_result_is_ok &= crc_check(crc_crc08_lte         , UINTMAX_C(0x00000000000000EA));
  crc_result_is_ok &= crc_check(crc_crc08_maxim       , UINTMAX_C(0x00000000000000A1));
  crc_result_is_ok &= crc_check(crc_crc08_opensafety  , UINTMAX_C(0x000000000000003E));
  crc_result_is_ok &= crc_check(crc_crc08_rohc        , UINTMAX_C(0x00000000000000D0));
  crc_result_is_ok &= crc_check(crc_crc08_sae_j1850   , UINTMAX_C(0x000000000000004B));
  crc_result_is_ok &= crc_check(crc_crc08_wcdma       , UINTMAX_C(0x0000000000000025));
  crc_result_is_ok &= crc_check(crc_crc10             , UINTMAX_C(0x0000000000000199));
  crc_result_is_ok &= crc_check(crc_crc10_cdma2000    , UINTMAX_C(0x0000000000000233));
  crc_result_is_ok &= crc_check(crc_crc10_gsm         , UINTMAX_C(0x000000000000012A));
  crc_result_is_ok &= crc_check(crc_crc11             , UINTMAX_C(0x00000000000005A3));
  crc_result_is_ok &= crc_check(crc_crc11_umts        , UINTMAX_C(0x0000000000000061));
  crc_result_is_ok &= crc_check(crc_crc12_cdma2000    , UINTMAX_C(0x0000000000000D4D));
  crc_result_is_ok &= crc_check(crc_crc12_dect        , UINTMAX_C(0x0000000000000F5B));
  crc_result_is_ok &= crc_check(crc_crc12_gsm         , UINTMAX_C(0x0000000000000B34));
  crc_result_is_ok &= crc_check(crc_crc12_umts        , UINTMAX_C(0x0000000000000DAF));
  crc_result_is_ok &= crc_check(crc_crc13_bbc         , UINTMAX_C(0x00000000000004FA));
  crc_result_is_ok &= crc_check(crc_crc14_darc        , UINTMAX_C(0x000000000000082D));
  crc_result_is_ok &= crc_check(crc_crc14_gsm         , UINTMAX_C(0x00000000000030AE));
  crc_result_is_ok &= crc_check(crc_crc15             , UINTMAX_C(0x000000000000059E));
  crc_result_is_ok &= crc_check(crc_crc15_mpt1327     , UINTMAX_C(0x0000000000002566));
  crc_result_is_ok &= crc_check(crc_crc16_arc         , UINTMAX_C(0x000000000000BB3D));
  crc_result_is_ok &= crc_check(crc_crc16_aug_ccitt   , UINTMAX_C(0x000000000000E5CC));
  crc_result_is_ok &= crc_check(crc_crc16_buypass     , UINTMAX_C(0x000000000000FEE8));
  crc_result_is_ok &= crc_check(crc_crc16_ccitt_false , UINTMAX_C(0x00000000000029B1));
  crc_result_is_ok &= crc_check(crc_crc16_cdma2000    , UINTMAX_C(0x0000000000004C06));
  crc_result_is_ok &= crc_check(crc_crc16_cms         , UINTMAX_C(0x000000000000AEE7));
  crc_result_is_ok &= crc_check(crc_crc16_dds_110     , UINTMAX_C(0x0000000000009ECF));
  crc_result_is_ok &= crc_check(crc_crc16_dect_r      , UINTMAX_C(0x000000000000007E));
  crc_result_is_ok &= crc_check(crc_crc16_dect_x      , UINTMAX_C(0x000000000000007F));
  crc_result_is_ok &= crc_check(crc_crc16_dnp         , UINTMAX_C(0x000000000000EA82));
  crc_result_is_ok &= crc_check(crc_crc16_en_13757    , UINTMAX_C(0x000000000000C2B7));
  crc_result_is_ok &= crc_check(crc_crc16_genibus     , UINTMAX_C(0x000000000000D64E));
  crc_result_is_ok &= crc_check(crc_crc16_gsm         , UINTMAX_C(0x000000000000CE3C));
  crc_result_is_ok &= crc_check(crc_crc16_lj1200      , UINTMAX_C(0x000000000000BDF4));
  crc_result_is_ok &= crc_check(crc_crc16_maxim       , UINTMAX_C(0x00000000000044C2));
  crc_result_is_ok &= crc_check(crc_crc16_mcrf4xx     , UINTMAX_C(0x0000000000006F91));
  crc_result_is_ok &= crc_check(crc_crc16_opensafety_a, UINTMAX_C(0x0000000000005D38));
  crc_result_is_ok &= crc_check(crc_crc16_opensafety_b, UINTMAX_C(0x00000000000020FE));
  crc_result_is_ok &= crc_check(crc_crc16_profibus    , UINTMAX_C(0x000000000000A819));
  crc_result_is_ok &= crc_check(crc_crc16_riello      , UINTMAX_C(0x00000000000063D0));
  crc_result_is_ok &= crc_check(crc_crc16_t10_dif     , UINTMAX_C(0x000000000000D0DB));
  crc_result_is_ok &= crc_check(crc_crc16_teledisk    , UINTMAX_C(0x0000000000000FB3));
  crc_result_is_ok &= crc_check(crc_crc16_tms37157    , UINTMAX_C(0x00000000000026B1));
  crc_result_is_ok &= crc_check(crc_crc16_usb         , UINTMAX_C(0x000000000000B4C8));
  crc_result_is_ok &= crc_check(crc_crc16_a           , UINTMAX_C(0x000000000000BF05));
  crc_result_is_ok &= crc_check(crc_crc16_kermit      , UINTMAX_C(0x0000000000002189));
  crc_result_is_ok &= crc_check(crc_crc16_modbus      , UINTMAX_C(0x0000000000004B37));
  crc_result_is_ok &= crc_check(crc_crc16_x_25        , UINTMAX_C(0x000000000000906E));
  crc_result_is_ok &= crc_check(crc_crc16_xmodem      , UINTMAX_C(0x00000000000031C3));
  crc_result_is_ok &= crc_check(crc_crc17_can_fd      , UINTMAX_C(0x0000000000004F03));
  crc_result_is_ok &= crc_check(crc_crc21_can_fd      , UINTMAX_C(0x00000000000ED841));
  crc_result_is_ok &= crc_check(crc_crc24             , UINTMAX_C(0x000000000021CF02));
  crc_result_is_ok &= crc_check(crc_crc24_ble         , UINTMAX_C(0x0000000000C25A56));
  crc_result_is_ok &= crc_check(crc_crc24_flexray_a   , UINTMAX_C(0x00000000007979BD));
  crc_result_is_ok &= crc_check(crc_crc24_flexray_b   , UINTMAX_C(0x00000000001F23B8));
  crc_result_is_ok &= crc_check(crc_crc24_interlaken  , UINTMAX_C(0x0000000000B4F3E6));
  crc_result_is_ok &= crc_check(crc_crc24_lte_a       , UINTMAX_C(0x0000000000CDE703));
  crc_result_is_ok &= crc_check(crc_crc24_lte_b       , UINTMAX_C(0x000000000023EF52));
  crc_result_is_ok &= crc_check(crc_crc30_cdma        , UINTMAX_C(0x0000000004C34ABF));
  crc_result_is_ok &= crc_check(crc_crc31_philips     , UINTMAX_C(0x000000000CE9E46C));
  crc_result_is_ok &= crc_check(crc_crc32             , UINTMAX_C(0x00000000CBF43926));
  crc_result_is_ok &= crc_check(crc_crc32_autosar     , UINTMAX_C(0x000000001697D06A));
  crc_result_is_ok &= crc_check(crc_crc32_bzip2       , UINTMAX_C(0x00000000FC891918));
  crc_result_is_ok &= crc_check(crc_crc32_c           , UINTMAX_C(0x00000000E3069283));
  crc_result_is_ok &= crc_check(crc_crc32_d           , UINTMAX_C(0x0000000087315576));
  crc_result_is_ok &= crc_check(crc_crc32_mpeg_2      , UINTMAX_C(0x000000000376E6E7));
  crc_result_is_ok &= crc_check(crc_crc32_posix       , UINTMAX_C(0x00000000765E7680));
  crc_result_is_ok &= crc_check(crc_crc32_q           , UINTMAX_C(0x000000003010BF7F));
  crc_result_is_ok &= crc_check(crc_crc32_jamcrc      , UINTMAX_C(0x00000000340BC6D9));
  crc_result_is_ok &= crc_check(crc_crc32_xfer        , UINTMAX_C(0x00000000BD0BE338));
  crc_result_is_ok &= crc_check(crc_crc40_gsm         , UINTMAX_C(0x000000D4164FC646));
  crc_result_is_ok &= crc_check(crc_crc64             , UINTMAX_C(0x6C40DF5F0B497347));
  crc_result_is_ok &= crc_check(crc_crc64_go_iso      , UINTMAX_C(0xB90956C775A41001));
  crc_result_is_ok &= crc_check(crc_crc64_we          , UINTMAX_C(0x62EC59E3F1A4F00A));
  crc_result_is_ok &= crc_check(crc_crc64_xz          , UINTMAX_C(0x995DC9BBDF1939FA));
  crc_result_is_ok &= crc_check(crc_crc64_jones_redis , UINTMAX_C(0xE9C6D914C4B8D9CA));

  std::cout << "crc_result_is_ok: " << std::boolalpha << crc_result_is_ok << std::endl;
}
