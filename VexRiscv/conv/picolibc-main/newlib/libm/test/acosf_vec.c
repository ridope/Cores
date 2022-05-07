/*
 * Copyright (c) 1994 Cygnus Support.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * and/or other materials related to such
 * distribution and use acknowledge that the software was developed
 * at Cygnus Support, Inc.  Cygnus Support, Inc. may not be used to
 * endorse or promote products derived from this software without
 * specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */
#include "test.h"
 one_line_type acosf_vec[] = {
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xbff33333, 0x33333333},	/* nan=f(-1.2)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xbff30a3d, 0x70a3d70a},	/* nan=f(-1.19)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xbff2e147, 0xae147ae1},	/* nan=f(-1.18)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xbff2b851, 0xeb851eb8},	/* nan=f(-1.17)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xbff28f5c, 0x28f5c28f},	/* nan=f(-1.16)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xbff26666, 0x66666666},	/* nan=f(-1.15)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xbff23d70, 0xa3d70a3d},	/* nan=f(-1.14)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xbff2147a, 0xe147ae14},	/* nan=f(-1.13)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xbff1eb85, 0x1eb851eb},	/* nan=f(-1.12)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xbff1c28f, 0x5c28f5c2},	/* nan=f(-1.11)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xbff19999, 0x99999999},	/* nan=f(-1.1)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xbff170a3, 0xd70a3d70},	/* nan=f(-1.09)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xbff147ae, 0x147ae147},	/* nan=f(-1.08)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xbff11eb8, 0x51eb851e},	/* nan=f(-1.07)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xbff0f5c2, 0x8f5c28f5},	/* nan=f(-1.06)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xbff0cccc, 0xcccccccc},	/* nan=f(-1.05)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xbff0a3d7, 0x0a3d70a3},	/* nan=f(-1.04)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xbff07ae1, 0x47ae147a},	/* nan=f(-1.03)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xbff051eb, 0x851eb851},	/* nan=f(-1.02)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xbff028f5, 0xc28f5c28},	/* nan=f(-1.01)*/
{36, 0,123,__LINE__, 0x400921fb, 0x54442d18, 0xbfefffff, 0xfffffffe},	/* 3.14159=f(-1)*/
{35, 0,123,__LINE__, 0x4008001b, 0xeacedde7, 0xbfefae14, 0x7ae147ac},	/* 3.00005=f(-0.99)*/
{37, 0,123,__LINE__, 0x400787b2, 0x39c14496, 0xbfef5c28, 0xf5c28f5a},	/* 2.94126=f(-0.98)*/
{36, 0,123,__LINE__, 0x40072b10, 0x5639d5db, 0xbfef0a3d, 0x70a3d708},	/* 2.89603=f(-0.97)*/
{36, 0,123,__LINE__, 0x4006dcc5, 0x716c4181, 0xbfeeb851, 0xeb851eb6},	/* 2.8578=f(-0.96)*/
{35, 0,123,__LINE__, 0x4006979e, 0x2fd1eb82, 0xbfee6666, 0x66666664},	/* 2.82403=f(-0.95)*/
{35, 0,123,__LINE__, 0x400658f0, 0x0efc7f78, 0xbfee147a, 0xe147ae12},	/* 2.79343=f(-0.94)*/
{40, 0,123,__LINE__, 0x40061f25, 0xff065424, 0xbfedc28f, 0x5c28f5c0},	/* 2.76521=f(-0.93)*/
{35, 0,123,__LINE__, 0x4005e938, 0x44b1fa46, 0xbfed70a3, 0xd70a3d6e},	/* 2.73888=f(-0.92)*/
{35, 0,123,__LINE__, 0x4005b66f, 0xcfdcfc12, 0xbfed1eb8, 0x51eb851c},	/* 2.71408=f(-0.91)*/
{37, 0,123,__LINE__, 0x40058647, 0x5afa87a2, 0xbfeccccc, 0xccccccca},	/* 2.69057=f(-0.9)*/
{35, 0,123,__LINE__, 0x4005585a, 0x8d684b09, 0xbfec7ae1, 0x47ae1478},	/* 2.66814=f(-0.89)*/
{35, 0,123,__LINE__, 0x40052c5b, 0x4cf8c34d, 0xbfec28f5, 0xc28f5c26},	/* 2.64666=f(-0.88)*/
{36, 0,123,__LINE__, 0x4005020b, 0x9579bfd4, 0xbfebd70a, 0x3d70a3d4},	/* 2.626=f(-0.87)*/
{35, 0,123,__LINE__, 0x4004d939, 0x25340d85, 0xbfeb851e, 0xb851eb82},	/* 2.60607=f(-0.86)*/
{36, 0,123,__LINE__, 0x4004b1ba, 0x960666cf, 0xbfeb3333, 0x33333330},	/* 2.58678=f(-0.85)*/
{38, 0,123,__LINE__, 0x40048b6d, 0x43eccaff, 0xbfeae147, 0xae147ade},	/* 2.56808=f(-0.84)*/
{35, 0,123,__LINE__, 0x40046634, 0x0efafa11, 0xbfea8f5c, 0x28f5c28c},	/* 2.5499=f(-0.83)*/
{35, 0,123,__LINE__, 0x400441f5, 0xeb118eb7, 0xbfea3d70, 0xa3d70a3a},	/* 2.53221=f(-0.82)*/
{35, 0,123,__LINE__, 0x40041e9d, 0x4a761249, 0xbfe9eb85, 0x1eb851e8},	/* 2.51495=f(-0.81)*/
{35, 0,123,__LINE__, 0x4003fc17, 0x6e25300b, 0xbfe99999, 0x99999996},	/* 2.49809=f(-0.8)*/
{35, 0,123,__LINE__, 0x4003da53, 0xe91ac1fa, 0xbfe947ae, 0x147ae144},	/* 2.48161=f(-0.79)*/
{36, 0,123,__LINE__, 0x4003b944, 0x314e2505, 0xbfe8f5c2, 0x8f5c28f2},	/* 2.46546=f(-0.78)*/
{37, 0,123,__LINE__, 0x400398db, 0x84c5501c, 0xbfe8a3d7, 0x0a3d70a0},	/* 2.44964=f(-0.77)*/
{34, 0,123,__LINE__, 0x4003790e, 0x5d0380bb, 0xbfe851eb, 0x851eb84e},	/* 2.43411=f(-0.76)*/
{35, 0,123,__LINE__, 0x400359d2, 0x6f93b6c3, 0xbfe7ffff, 0xfffffffc},	/* 2.41886=f(-0.75)*/
{36, 0,123,__LINE__, 0x40033b1e, 0x76cc05ae, 0xbfe7ae14, 0x7ae147aa},	/* 2.40387=f(-0.74)*/
{35, 0,123,__LINE__, 0x40031cea, 0x0edd7bcd, 0xbfe75c28, 0xf5c28f58},	/* 2.38912=f(-0.73)*/
{37, 0,123,__LINE__, 0x4002ff2d, 0x98acc17c, 0xbfe70a3d, 0x70a3d706},	/* 2.3746=f(-0.72)*/
{36, 0,123,__LINE__, 0x4002e1e2, 0x15f64117, 0xbfe6b851, 0xeb851eb4},	/* 2.36029=f(-0.71)*/
{38, 0,123,__LINE__, 0x4002c501, 0x422f47f0, 0xbfe66666, 0x66666662},	/* 2.34619=f(-0.7)*/
{38, 0,123,__LINE__, 0x4002a885, 0x3c3f69f8, 0xbfe6147a, 0xe147ae10},	/* 2.33229=f(-0.69)*/
{35, 0,123,__LINE__, 0x40028c68, 0xa5598d50, 0xbfe5c28f, 0x5c28f5be},	/* 2.31856=f(-0.68)*/
{35, 0,123,__LINE__, 0x400270a6, 0x887aed21, 0xbfe570a3, 0xd70a3d6c},	/* 2.30501=f(-0.67)*/
{35, 0,123,__LINE__, 0x4002553a, 0x4f33ccb3, 0xbfe51eb8, 0x51eb851a},	/* 2.29162=f(-0.66)*/
{35, 0,123,__LINE__, 0x40023a1f, 0xad63407d, 0xbfe4cccc, 0xccccccc8},	/* 2.27838=f(-0.65)*/
{38, 0,123,__LINE__, 0x40021f52, 0xc2f25bcc, 0xbfe47ae1, 0x47ae1476},	/* 2.26529=f(-0.64)*/
{36, 0,123,__LINE__, 0x400204cf, 0xd4e04b72, 0xbfe428f5, 0xc28f5c24},	/* 2.25235=f(-0.63)*/
{36, 0,123,__LINE__, 0x4001ea93, 0x71307330, 0xbfe3d70a, 0x3d70a3d2},	/* 2.23954=f(-0.62)*/
{39, 0,123,__LINE__, 0x4001d09a, 0x5e801d96, 0xbfe3851e, 0xb851eb80},	/* 2.22686=f(-0.61)*/
{36, 0,123,__LINE__, 0x4001b6e1, 0x96ebbe45, 0xbfe33333, 0x3333332e},	/* 2.2143=f(-0.6)*/
{37, 0,123,__LINE__, 0x40019d66, 0x399df664, 0xbfe2e147, 0xae147adc},	/* 2.20186=f(-0.59)*/
{35, 0,123,__LINE__, 0x40018425, 0xae7e6c57, 0xbfe28f5c, 0x28f5c28a},	/* 2.18952=f(-0.58)*/
{35, 0,123,__LINE__, 0x40016b1d, 0x66dec32f, 0xbfe23d70, 0xa3d70a38},	/* 2.1773=f(-0.57)*/
{38, 0,123,__LINE__, 0x4001524b, 0x0226a846, 0xbfe1eb85, 0x1eb851e6},	/* 2.16518=f(-0.56)*/
{40, 0,123,__LINE__, 0x400139ac, 0x40ec947d, 0xbfe19999, 0x99999994},	/* 2.15316=f(-0.55)*/
{38, 0,123,__LINE__, 0x4001213f, 0x0258720f, 0xbfe147ae, 0x147ae142},	/* 2.14123=f(-0.54)*/
{37, 0,123,__LINE__, 0x40010901, 0x38583c30, 0xbfe0f5c2, 0x8f5c28f0},	/* 2.1294=f(-0.53)*/
{36, 0,123,__LINE__, 0x4000f0f1, 0x0b4b0aac, 0xbfe0a3d7, 0x0a3d709e},	/* 2.11765=f(-0.52)*/
{34, 0,123,__LINE__, 0x4000d90c, 0x9f418b6d, 0xbfe051eb, 0x851eb84c},	/* 2.10598=f(-0.51)*/
{37, 0,123,__LINE__, 0x4000c152, 0x382d7366, 0xbfdfffff, 0xfffffff4},	/* 2.0944=f(-0.5)*/
{35, 0,123,__LINE__, 0x4000a9c0, 0x2ec5bd16, 0xbfdf5c28, 0xf5c28f50},	/* 2.08289=f(-0.49)*/
{35, 0,123,__LINE__, 0x40009254, 0xea80cd76, 0xbfdeb851, 0xeb851eac},	/* 2.07145=f(-0.48)*/
{36, 0,123,__LINE__, 0x40007b0e, 0xf2821f98, 0xbfde147a, 0xe147ae08},	/* 2.06009=f(-0.47)*/
{36, 0,123,__LINE__, 0x400063ec, 0xd0ef4599, 0xbfdd70a3, 0xd70a3d64},	/* 2.04879=f(-0.46)*/
{41, 0,123,__LINE__, 0x40004ced, 0x1fa8570e, 0xbfdccccc, 0xccccccc0},	/* 2.03756=f(-0.45)*/
{36, 0,123,__LINE__, 0x4000360e, 0x94998d21, 0xbfdc28f5, 0xc28f5c1c},	/* 2.02639=f(-0.44)*/
{37, 0,123,__LINE__, 0x40001f4f, 0xe5d44797, 0xbfdb851e, 0xb851eb78},	/* 2.01529=f(-0.43)*/
{36, 0,123,__LINE__, 0x400008af, 0xd6440d3d, 0xbfdae147, 0xae147ad4},	/* 2.00424=f(-0.42)*/
{37, 0,123,__LINE__, 0x3fffe45a, 0x840932fe, 0xbfda3d70, 0xa3d70a30},	/* 1.99325=f(-0.41)*/
{37, 0,123,__LINE__, 0x3fffb78e, 0x063ce4ab, 0xbfd99999, 0x9999998c},	/* 1.98231=f(-0.4)*/
{38, 0,123,__LINE__, 0x3fff8af7, 0xfc5ef2d3, 0xbfd8f5c2, 0x8f5c28e8},	/* 1.97143=f(-0.39)*/
{38, 0,123,__LINE__, 0x3fff5e96, 0x5d7943a5, 0xbfd851eb, 0x851eb844},	/* 1.96059=f(-0.38)*/
{37, 0,123,__LINE__, 0x3fff3267, 0x18f15645, 0xbfd7ae14, 0x7ae147a0},	/* 1.94981=f(-0.37)*/
{37, 0,123,__LINE__, 0x3fff0668, 0x38497f95, 0xbfd70a3d, 0x70a3d6fc},	/* 1.93906=f(-0.36)*/
{35, 0,123,__LINE__, 0x3ffeda97, 0xccd15a60, 0xbfd66666, 0x66666658},	/* 1.92837=f(-0.35)*/
{36, 0,123,__LINE__, 0x3ffeaef4, 0x10de72a1, 0xbfd5c28f, 0x5c28f5b4},	/* 1.91771=f(-0.34)*/
{36, 0,123,__LINE__, 0x3ffe837b, 0x338bcc9e, 0xbfd51eb8, 0x51eb8510},	/* 1.9071=f(-0.33)*/
{36, 0,123,__LINE__, 0x3ffe582b, 0x71b1bfba, 0xbfd47ae1, 0x47ae146c},	/* 1.89653=f(-0.32)*/
{35, 0,123,__LINE__, 0x3ffe2d03, 0x2e54aa55, 0xbfd3d70a, 0x3d70a3c8},	/* 1.88599=f(-0.31)*/
{40, 0,123,__LINE__, 0x3ffe0200, 0xbf242c1c, 0xbfd33333, 0x33333324},	/* 1.87549=f(-0.3)*/
{37, 0,123,__LINE__, 0x3ffdd722, 0x8548c8f8, 0xbfd28f5c, 0x28f5c280},	/* 1.86502=f(-0.29)*/
{37, 0,123,__LINE__, 0x3ffdac67, 0x05b710a5, 0xbfd1eb85, 0x1eb851dc},	/* 1.85459=f(-0.28)*/
{36, 0,123,__LINE__, 0x3ffd81cc, 0xb6539bb5, 0xbfd147ae, 0x147ae138},	/* 1.84419=f(-0.27)*/
{36, 0,123,__LINE__, 0x3ffd5752, 0x16974b6f, 0xbfd0a3d7, 0x0a3d7094},	/* 1.83382=f(-0.26)*/
{37, 0,123,__LINE__, 0x3ffd2cf5, 0xc7c70f0c, 0xbfcfffff, 0xffffffe0},	/* 1.82348=f(-0.25)*/
{36, 0,123,__LINE__, 0x3ffd02b6, 0x568682a7, 0xbfceb851, 0xeb851e98},	/* 1.81316=f(-0.24)*/
{35, 0,123,__LINE__, 0x3ffcd892, 0x6c0b3944, 0xbfcd70a3, 0xd70a3d50},	/* 1.80287=f(-0.23)*/
{35, 0,123,__LINE__, 0x3ffcae88, 0xa8793619, 0xbfcc28f5, 0xc28f5c08},	/* 1.79261=f(-0.22)*/
{40, 0,123,__LINE__, 0x3ffc8497, 0xbf445b53, 0xbfcae147, 0xae147ac0},	/* 1.78237=f(-0.21)*/
{35, 0,123,__LINE__, 0x3ffc5abe, 0x6a5e8f4b, 0xbfc99999, 0x99999978},	/* 1.77215=f(-0.2)*/
{38, 0,123,__LINE__, 0x3ffc30fb, 0x5d96a429, 0xbfc851eb, 0x851eb830},	/* 1.76196=f(-0.19)*/
{35, 0,123,__LINE__, 0x3ffc074d, 0x62c9d373, 0xbfc70a3d, 0x70a3d6e8},	/* 1.75178=f(-0.18)*/
{37, 0,123,__LINE__, 0x3ffbddb3, 0x38e26843, 0xbfc5c28f, 0x5c28f5a0},	/* 1.74163=f(-0.17)*/
{35, 0,123,__LINE__, 0x3ffbb42b, 0xaffe6e20, 0xbfc47ae1, 0x47ae1458},	/* 1.73149=f(-0.16)*/
{38, 0,123,__LINE__, 0x3ffb8ab5, 0x9cd8b878, 0xbfc33333, 0x33333310},	/* 1.72136=f(-0.15)*/
{35, 0,123,__LINE__, 0x3ffb614f, 0xcc5600ce, 0xbfc1eb85, 0x1eb851c8},	/* 1.71126=f(-0.14)*/
{37, 0,123,__LINE__, 0x3ffb37f9, 0x1b7d7f7e, 0xbfc0a3d7, 0x0a3d7080},	/* 1.70117=f(-0.13)*/
{35, 0,123,__LINE__, 0x3ffb0eb0, 0x68f951c1, 0xbfbeb851, 0xeb851e71},	/* 1.69109=f(-0.12)*/
{36, 0,123,__LINE__, 0x3ffae574, 0x92ca5eb8, 0xbfbc28f5, 0xc28f5be2},	/* 1.68102=f(-0.11)*/
{38, 0,123,__LINE__, 0x3ffabc44, 0x7c0b4f17, 0xbfb99999, 0x99999953},	/* 1.67096=f(-0.1)*/
{35, 0,123,__LINE__, 0x3ffa931f, 0x0aa2c568, 0xbfb70a3d, 0x70a3d6c4},	/* 1.66092=f(-0.09)*/
{35, 0,123,__LINE__, 0x3ffa6a03, 0x24fae9c3, 0xbfb47ae1, 0x47ae1435},	/* 1.65088=f(-0.08)*/
{37, 0,123,__LINE__, 0x3ffa40ef, 0xb9c34207, 0xbfb1eb85, 0x1eb851a6},	/* 1.64085=f(-0.07)*/
{36, 0,123,__LINE__, 0x3ffa17e3, 0xb2a18053, 0xbfaeb851, 0xeb851e2d},	/* 1.63083=f(-0.06)*/
{45, 0,123,__LINE__, 0x3ff9eedd, 0xfff904e8, 0xbfa99999, 0x9999990e},	/* 1.62082=f(-0.05)*/
{35, 0,123,__LINE__, 0x3ff9c5dd, 0x8fa425c6, 0xbfa47ae1, 0x47ae13ef},	/* 1.61081=f(-0.04)*/
{36, 0,123,__LINE__, 0x3ff99ce1, 0x54371bee, 0xbf9eb851, 0xeb851da0},	/* 1.6008=f(-0.03)*/
{40, 0,123,__LINE__, 0x3ff973e8, 0x3f3ea2b6, 0xbf947ae1, 0x47ae1362},	/* 1.5908=f(-0.02)*/
{38, 0,123,__LINE__, 0x3ff94af1, 0x4381efdb, 0xbf847ae1, 0x47ae1249},	/* 1.5808=f(-0.01)*/
{36, 0,123,__LINE__, 0x3ff921fb, 0x54442d14, 0x3cd19000, 0x00000000},	/* 1.5708=f(9.74915e-16)*/
{35, 0,123,__LINE__, 0x3ff8f905, 0x65066a56, 0x3f847ae1, 0x47ae16ad},	/* 1.5608=f(0.01)*/
{35, 0,123,__LINE__, 0x3ff8d00e, 0x6949b77b, 0x3f947ae1, 0x47ae1594},	/* 1.55079=f(0.02)*/
{36, 0,123,__LINE__, 0x3ff8a715, 0x54513e43, 0x3f9eb851, 0xeb851fd2},	/* 1.54079=f(0.03)*/
{37, 0,123,__LINE__, 0x3ff87e19, 0x18e4346a, 0x3fa47ae1, 0x47ae1508},	/* 1.53079=f(0.04)*/
{35, 0,123,__LINE__, 0x3ff85518, 0xa88f5548, 0x3fa99999, 0x99999a27},	/* 1.52078=f(0.05)*/
{36, 0,123,__LINE__, 0x3ff82c12, 0xf5e6d9de, 0x3faeb851, 0xeb851f46},	/* 1.51076=f(0.06)*/
{35, 0,123,__LINE__, 0x3ff80306, 0xeec5182a, 0x3fb1eb85, 0x1eb85232},	/* 1.50074=f(0.07)*/
{38, 0,123,__LINE__, 0x3ff7d9f3, 0x838d706d, 0x3fb47ae1, 0x47ae14c1},	/* 1.49071=f(0.08)*/
{38, 0,123,__LINE__, 0x3ff7b0d7, 0x9de594c9, 0x3fb70a3d, 0x70a3d750},	/* 1.48067=f(0.09)*/
{35, 0,123,__LINE__, 0x3ff787b2, 0x2c7d0b19, 0x3fb99999, 0x999999df},	/* 1.47063=f(0.1)*/
{36, 0,123,__LINE__, 0x3ff75e82, 0x15bdfb79, 0x3fbc28f5, 0xc28f5c6e},	/* 1.46057=f(0.11)*/
{41, 0,123,__LINE__, 0x3ff73546, 0x3f8f086f, 0x3fbeb851, 0xeb851efd},	/* 1.45051=f(0.12)*/
{35, 0,123,__LINE__, 0x3ff70bfd, 0x8d0adab2, 0x3fc0a3d7, 0x0a3d70c6},	/* 1.44043=f(0.13)*/
{38, 0,123,__LINE__, 0x3ff6e2a6, 0xdc325963, 0x3fc1eb85, 0x1eb8520e},	/* 1.43033=f(0.14)*/
{35, 0,123,__LINE__, 0x3ff6b941, 0x0bafa1b9, 0x3fc33333, 0x33333356},	/* 1.42023=f(0.15)*/
{37, 0,123,__LINE__, 0x3ff68fca, 0xf889ec10, 0x3fc47ae1, 0x47ae149e},	/* 1.41011=f(0.16)*/
{35, 0,123,__LINE__, 0x3ff66643, 0x6fa5f1ed, 0x3fc5c28f, 0x5c28f5e6},	/* 1.39997=f(0.17)*/
{37, 0,123,__LINE__, 0x3ff63ca9, 0x45be86bd, 0x3fc70a3d, 0x70a3d72e},	/* 1.38981=f(0.18)*/
{35, 0,123,__LINE__, 0x3ff612fb, 0x4af1b607, 0x3fc851eb, 0x851eb876},	/* 1.37963=f(0.19)*/
{39, 0,123,__LINE__, 0x3ff5e938, 0x3e29cae5, 0x3fc99999, 0x999999be},	/* 1.36944=f(0.2)*/
{35, 0,123,__LINE__, 0x3ff5bf5e, 0xe943fede, 0x3fcae147, 0xae147b06},	/* 1.35922=f(0.21)*/
{44, 0,123,__LINE__, 0x3ff5956e, 0x000f2418, 0x3fcc28f5, 0xc28f5c4e},	/* 1.34898=f(0.22)*/
{38, 0,123,__LINE__, 0x3ff56b64, 0x3c7d20ed, 0x3fcd70a3, 0xd70a3d96},	/* 1.33872=f(0.23)*/
{36, 0,123,__LINE__, 0x3ff54140, 0x5201d789, 0x3fceb851, 0xeb851ede},	/* 1.32843=f(0.24)*/
{35, 0,123,__LINE__, 0x3ff51700, 0xe0c14b25, 0x3fd00000, 0x00000013},	/* 1.31812=f(0.25)*/
{36, 0,123,__LINE__, 0x3ff4eca4, 0x91f10ec1, 0x3fd0a3d7, 0x0a3d70b7},	/* 1.30777=f(0.26)*/
{36, 0,123,__LINE__, 0x3ff4c229, 0xf234be7b, 0x3fd147ae, 0x147ae15b},	/* 1.2974=f(0.27)*/
{35, 0,123,__LINE__, 0x3ff4978f, 0xa2d1498c, 0x3fd1eb85, 0x1eb851ff},	/* 1.287=f(0.28)*/
{35, 0,123,__LINE__, 0x3ff46cd4, 0x233f9139, 0x3fd28f5c, 0x28f5c2a3},	/* 1.27657=f(0.29)*/
{35, 0,123,__LINE__, 0x3ff441f5, 0xe9642e15, 0x3fd33333, 0x33333347},	/* 1.2661=f(0.3)*/
{37, 0,123,__LINE__, 0x3ff416f3, 0x7a33afdc, 0x3fd3d70a, 0x3d70a3eb},	/* 1.2556=f(0.31)*/
{36, 0,123,__LINE__, 0x3ff3ebcb, 0x36d69a77, 0x3fd47ae1, 0x47ae148f},	/* 1.24507=f(0.32)*/
{36, 0,123,__LINE__, 0x3ff3c07b, 0x74fc8d92, 0x3fd51eb8, 0x51eb8533},	/* 1.23449=f(0.33)*/
{36, 0,123,__LINE__, 0x3ff39502, 0x97a9e78f, 0x3fd5c28f, 0x5c28f5d7},	/* 1.22388=f(0.34)*/
{37, 0,123,__LINE__, 0x3ff3695e, 0xdbb6ffd0, 0x3fd66666, 0x6666667b},	/* 1.21323=f(0.35)*/
{36, 0,123,__LINE__, 0x3ff33d8e, 0x703eda9b, 0x3fd70a3d, 0x70a3d71f},	/* 1.20253=f(0.36)*/
{35, 0,123,__LINE__, 0x3ff3118f, 0x8f9703ec, 0x3fd7ae14, 0x7ae147c3},	/* 1.19179=f(0.37)*/
{35, 0,123,__LINE__, 0x3ff2e560, 0x4b0f168c, 0x3fd851eb, 0x851eb867},	/* 1.181=f(0.38)*/
{35, 0,123,__LINE__, 0x3ff2b8fe, 0xac29675d, 0x3fd8f5c2, 0x8f5c290b},	/* 1.17016=f(0.39)*/
{35, 0,123,__LINE__, 0x3ff28c68, 0xa24b7586, 0x3fd99999, 0x999999af},	/* 1.15928=f(0.4)*/
{35, 0,123,__LINE__, 0x3ff25f9c, 0x247f2732, 0x3fda3d70, 0xa3d70a53},	/* 1.14834=f(0.41)*/
{38, 0,123,__LINE__, 0x3ff23296, 0xfc003fb6, 0x3fdae147, 0xae147af7},	/* 1.13735=f(0.42)*/
{38, 0,123,__LINE__, 0x3ff20556, 0xdcdfcb02, 0x3fdb851e, 0xb851eb9b},	/* 1.1263=f(0.43)*/
{40, 0,123,__LINE__, 0x3ff1d7d9, 0x7f553fef, 0x3fdc28f5, 0xc28f5c3f},	/* 1.1152=f(0.44)*/
{35, 0,123,__LINE__, 0x3ff1aa1c, 0x6937ac16, 0x3fdccccc, 0xcccccce3},	/* 1.10403=f(0.45)*/
{37, 0,123,__LINE__, 0x3ff17c1d, 0x06a9cefe, 0x3fdd70a3, 0xd70a3d87},	/* 1.0928=f(0.46)*/
{38, 0,123,__LINE__, 0x3ff14dd8, 0xc3841b01, 0x3fde147a, 0xe147ae2b},	/* 1.08151=f(0.47)*/
{36, 0,123,__LINE__, 0x3ff11f4c, 0xd386bf45, 0x3fdeb851, 0xeb851ecf},	/* 1.07014=f(0.48)*/
{36, 0,123,__LINE__, 0x3ff0f076, 0x4afce004, 0x3fdf5c28, 0xf5c28f73},	/* 1.05871=f(0.49)*/
{37, 0,123,__LINE__, 0x3ff0c152, 0x382d7366, 0x3fe00000, 0x0000000b},	/* 1.0472=f(0.5)*/
{36, 0,123,__LINE__, 0x3ff091dd, 0x6a054356, 0x3fe051eb, 0x851eb85d},	/* 1.03561=f(0.51)*/
{36, 0,123,__LINE__, 0x3ff06214, 0x91f244d8, 0x3fe0a3d7, 0x0a3d70af},	/* 1.02395=f(0.52)*/
{36, 0,123,__LINE__, 0x3ff031f4, 0x37d7e1d1, 0x3fe0f5c2, 0x8f5c2901},	/* 1.0122=f(0.53)*/
{38, 0,123,__LINE__, 0x3ff00178, 0xa3d77612, 0x3fe147ae, 0x147ae153},	/* 1.00036=f(0.54)*/
{36, 0,123,__LINE__, 0x3fefa13c, 0x4d5e626d, 0x3fe19999, 0x999999a5},	/* 0.988432=f(0.55)*/
{35, 0,123,__LINE__, 0x3fef3ec1, 0x48761349, 0x3fe1eb85, 0x1eb851f7},	/* 0.976411=f(0.56)*/
{35, 0,123,__LINE__, 0x3feedb77, 0xb595a7a3, 0x3fe23d70, 0xa3d70a49},	/* 0.96429=f(0.57)*/
{36, 0,123,__LINE__, 0x3fee7756, 0x97170304, 0x3fe28f5c, 0x28f5c29b},	/* 0.952068=f(0.58)*/
{35, 0,123,__LINE__, 0x3fee1254, 0x6a98dad1, 0x3fe2e147, 0xae147aed},	/* 0.939738=f(0.59)*/
{36, 0,123,__LINE__, 0x3fedac66, 0xf561bb4c, 0x3fe33333, 0x3333333f},	/* 0.927295=f(0.6)*/
{36, 0,123,__LINE__, 0x3fed4583, 0xd7103e09, 0x3fe3851e, 0xb851eb91},	/* 0.914736=f(0.61)*/
{35, 0,123,__LINE__, 0x3fecdd9f, 0x8c4ee7a3, 0x3fe3d70a, 0x3d70a3e3},	/* 0.902054=f(0.62)*/
{38, 0,123,__LINE__, 0x3fec74ad, 0xfd8f869a, 0x3fe428f5, 0xc28f5c35},	/* 0.889243=f(0.63)*/
{37, 0,123,__LINE__, 0x3fec0aa2, 0x45474531, 0x3fe47ae1, 0x47ae1487},	/* 0.876298=f(0.64)*/
{35, 0,123,__LINE__, 0x3feb9f6e, 0x9b83b26f, 0x3fe4cccc, 0xccccccd9},	/* 0.863212=f(0.65)*/
{35, 0,123,__LINE__, 0x3feb3304, 0x14418197, 0x3fe51eb8, 0x51eb852b},	/* 0.849978=f(0.66)*/
{36, 0,123,__LINE__, 0x3feac553, 0x2f24ffdd, 0x3fe570a3, 0xd70a3d7d},	/* 0.836588=f(0.67)*/
{37, 0,123,__LINE__, 0x3fea564a, 0xbbaa7f23, 0x3fe5c28f, 0x5c28f5cf},	/* 0.823034=f(0.68)*/
{43, 0,123,__LINE__, 0x3fe9e5d8, 0x60130c83, 0x3fe6147a, 0xe147ae21},	/* 0.809307=f(0.69)*/
{36, 0,123,__LINE__, 0x3fe973e8, 0x485394a3, 0x3fe66666, 0x66666673},	/* 0.795399=f(0.7)*/
{37, 0,123,__LINE__, 0x3fe90064, 0xf937b006, 0x3fe6b851, 0xeb851ec5},	/* 0.781298=f(0.71)*/
{36, 0,123,__LINE__, 0x3fe88b36, 0xee5dae70, 0x3fe70a3d, 0x70a3d717},	/* 0.766994=f(0.72)*/
{36, 0,123,__LINE__, 0x3fe81445, 0x159ac52b, 0x3fe75c28, 0xf5c28f69},	/* 0.752474=f(0.73)*/
{35, 0,123,__LINE__, 0x3fe79b73, 0x75e09da8, 0x3fe7ae14, 0x7ae147bb},	/* 0.737726=f(0.74)*/
{35, 0,123,__LINE__, 0x3fe720a3, 0x92c1d955, 0x3fe80000, 0x0000000d},	/* 0.722734=f(0.75)*/
{35, 0,123,__LINE__, 0x3fe6a3b3, 0xdd02b176, 0x3fe851eb, 0x851eb85f},	/* 0.707483=f(0.76)*/
{38, 0,123,__LINE__, 0x3fe6247f, 0x3dfb73f3, 0x3fe8a3d7, 0x0a3d70b1},	/* 0.691955=f(0.77)*/
{35, 0,123,__LINE__, 0x3fe5a2dc, 0x8bd8204b, 0x3fe8f5c2, 0x8f5c2903},	/* 0.676131=f(0.78)*/
{36, 0,123,__LINE__, 0x3fe51e9d, 0xaca5ac79, 0x3fe947ae, 0x147ae155},	/* 0.659987=f(0.79)*/
{37, 0,123,__LINE__, 0x3fe4978f, 0x987bf434, 0x3fe99999, 0x999999a7},	/* 0.643501=f(0.8)*/
{37, 0,123,__LINE__, 0x3fe40d78, 0x27386b3c, 0x3fe9eb85, 0x1eb851f9},	/* 0.626644=f(0.81)*/
{37, 0,123,__LINE__, 0x3fe38015, 0xa4ca7985, 0x3fea3d70, 0xa3d70a4b},	/* 0.609385=f(0.82)*/
{35, 0,123,__LINE__, 0x3fe2ef1d, 0x1524cc1e, 0x3fea8f5c, 0x28f5c29d},	/* 0.591689=f(0.83)*/
{39, 0,123,__LINE__, 0x3fe25a38, 0x415d8866, 0x3feae147, 0xae147aef},	/* 0.573513=f(0.84)*/
{37, 0,123,__LINE__, 0x3fe1c102, 0xf8f71926, 0x3feb3333, 0x33333341},	/* 0.554811=f(0.85)*/
{38, 0,123,__LINE__, 0x3fe12308, 0xbc407e4d, 0x3feb851e, 0xb851eb93},	/* 0.535527=f(0.86)*/
{37, 0,123,__LINE__, 0x3fe07fbe, 0xfb29b513, 0x3febd70a, 0x3d70a3e5},	/* 0.515594=f(0.87)*/
{37, 0,123,__LINE__, 0x3fdfad00, 0x3a5b4e57, 0x3fec28f5, 0xc28f5c37},	/* 0.494934=f(0.88)*/
{36, 0,123,__LINE__, 0x3fde4d06, 0x36df1077, 0x3fec7ae1, 0x47ae1489},	/* 0.473451=f(0.89)*/
{36, 0,123,__LINE__, 0x3fdcdd9f, 0xca4d2bb4, 0x3feccccc, 0xccccccdb},	/* 0.451027=f(0.9)*/
{38, 0,123,__LINE__, 0x3fdb5c5c, 0x23398834, 0x3fed1eb8, 0x51eb852d},	/* 0.427512=f(0.91)*/
{35, 0,123,__LINE__, 0x3fd9c618, 0x7c919692, 0x3fed70a3, 0xd70a3d7f},	/* 0.402716=f(0.92)*/
{36, 0,123,__LINE__, 0x3fd816aa, 0xa9eec7a1, 0x3fedc28f, 0x5c28f5d1},	/* 0.376383=f(0.93)*/
{36, 0,123,__LINE__, 0x3fd6485a, 0x2a3d6d03, 0x3fee147a, 0xe147ae23},	/* 0.348166=f(0.94)*/
{38, 0,123,__LINE__, 0x3fd452e9, 0x23920cb1, 0x3fee6666, 0x66666675},	/* 0.31756=f(0.95)*/
{36, 0,123,__LINE__, 0x3fd229af, 0x16bf5cb9, 0x3feeb851, 0xeb851ec7},	/* 0.283794=f(0.96)*/
{40, 0,123,__LINE__, 0x3fcf6eaf, 0xe0a573d0, 0x3fef0a3d, 0x70a3d719},	/* 0.245565=f(0.97)*/
{36, 0,123,__LINE__, 0x3fc9a491, 0xa82e881f, 0x3fef5c28, 0xf5c28f6b},	/* 0.200335=f(0.98)*/
{36, 0,123,__LINE__, 0x3fc21df6, 0x9754f31a, 0x3fefae14, 0x7ae147bd},	/* 0.141539=f(0.99)*/
{64, 0,123,__LINE__, 0x00000000, 0x00000000, 0x3ff00000, 0x00000007},	/* 0=f(1)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x3ff028f5, 0xc28f5c30},	/* nan=f(1.01)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x3ff051eb, 0x851eb859},	/* nan=f(1.02)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x3ff07ae1, 0x47ae1482},	/* nan=f(1.03)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x3ff0a3d7, 0x0a3d70ab},	/* nan=f(1.04)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x3ff0cccc, 0xccccccd4},	/* nan=f(1.05)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x3ff0f5c2, 0x8f5c28fd},	/* nan=f(1.06)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x3ff11eb8, 0x51eb8526},	/* nan=f(1.07)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x3ff147ae, 0x147ae14f},	/* nan=f(1.08)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x3ff170a3, 0xd70a3d78},	/* nan=f(1.09)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x3ff19999, 0x999999a1},	/* nan=f(1.1)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x3ff1c28f, 0x5c28f5ca},	/* nan=f(1.11)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x3ff1eb85, 0x1eb851f3},	/* nan=f(1.12)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x3ff2147a, 0xe147ae1c},	/* nan=f(1.13)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x3ff23d70, 0xa3d70a45},	/* nan=f(1.14)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x3ff26666, 0x6666666e},	/* nan=f(1.15)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x3ff28f5c, 0x28f5c297},	/* nan=f(1.16)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x3ff2b851, 0xeb851ec0},	/* nan=f(1.17)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x3ff2e147, 0xae147ae9},	/* nan=f(1.18)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x3ff30a3d, 0x70a3d712},	/* nan=f(1.19)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xc01921fb, 0x54442d18},	/* nan=f(-6.28319)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xc012d97c, 0x7f3321d2},	/* nan=f(-4.71239)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xc00921fb, 0x54442d18},	/* nan=f(-3.14159)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xbff921fb, 0x54442d18},	/* nan=f(-1.5708)*/
{36, 0,123,__LINE__, 0x3ff921fb, 0x54442d18, 0x00000000, 0x00000000},	/* 1.5708=f(0)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x3ff921fb, 0x54442d18},	/* nan=f(1.5708)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x400921fb, 0x54442d18},	/* nan=f(3.14159)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x4012d97c, 0x7f3321d2},	/* nan=f(4.71239)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xc03e0000, 0x00000000},	/* nan=f(-30)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xc03c4ccc, 0xcccccccd},	/* nan=f(-28.3)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xc03a9999, 0x9999999a},	/* nan=f(-26.6)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xc038e666, 0x66666667},	/* nan=f(-24.9)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xc0373333, 0x33333334},	/* nan=f(-23.2)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xc0358000, 0x00000001},	/* nan=f(-21.5)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xc033cccc, 0xccccccce},	/* nan=f(-19.8)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xc0321999, 0x9999999b},	/* nan=f(-18.1)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xc0306666, 0x66666668},	/* nan=f(-16.4)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xc02d6666, 0x6666666a},	/* nan=f(-14.7)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xc02a0000, 0x00000004},	/* nan=f(-13)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xc0269999, 0x9999999e},	/* nan=f(-11.3)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xc0233333, 0x33333338},	/* nan=f(-9.6)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xc01f9999, 0x999999a3},	/* nan=f(-7.9)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xc018cccc, 0xccccccd6},	/* nan=f(-6.2)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xc0120000, 0x00000009},	/* nan=f(-4.5)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xc0066666, 0x66666678},	/* nan=f(-2.8)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0xbff19999, 0x999999bd},	/* nan=f(-1.1)*/
{36, 0,123,__LINE__, 0x3fedac66, 0xf561bb4c, 0x3fe33333, 0x333332ec},	/* 0.927295=f(0.6)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x40026666, 0x66666654},	/* nan=f(2.3)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x400fffff, 0xffffffee},	/* nan=f(4)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x4016cccc, 0xccccccc4},	/* nan=f(5.7)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x401d9999, 0x99999991},	/* nan=f(7.4)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x40223333, 0x3333332f},	/* nan=f(9.1)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x40259999, 0x99999995},	/* nan=f(10.8)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x4028ffff, 0xfffffffb},	/* nan=f(12.5)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x402c6666, 0x66666661},	/* nan=f(14.2)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x402fcccc, 0xccccccc7},	/* nan=f(15.9)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x40319999, 0x99999997},	/* nan=f(17.6)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x40334ccc, 0xccccccca},	/* nan=f(19.3)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x4034ffff, 0xfffffffd},	/* nan=f(21)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x4036b333, 0x33333330},	/* nan=f(22.7)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x40386666, 0x66666663},	/* nan=f(24.4)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x403a1999, 0x99999996},	/* nan=f(26.1)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x403bcccc, 0xccccccc9},	/* nan=f(27.8)*/
{32, 0, 33,__LINE__, 0x7ff80000, 0x00000000, 0x403d7fff, 0xfffffffc},	/* nan=f(29.5)*/
{0}
};
void test_acosf(int m)   {run_vector_1(m,acosf_vec,(char *)(acosf),"acosf","ff");   }	
