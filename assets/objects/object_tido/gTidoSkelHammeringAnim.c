#include "ultra64.h"
#include "global.h"

s16 gTidoSkelHammeringAnimFrameData[166] = {
	0x0000, 0x0402, 0x00c2, 0xbfff, 0x0e39, 0xf8e3, 0xdc71, 0x0578, 0x048f, 0x23dd, 0xb1c6, 0x071c, 0xfa87, 0xfb70, 0x7ca2, 0x0adc, 
	0xecb5, 0x501c, 0x0222, 0x03db, 0xfde0, 0x26a4, 0xee22, 0xf052, 0x4000, 0x0794, 0xaee8, 0xb0df, 0xb5ee, 0xbcce, 0xc43d, 0xcb1f, 
	0xd0ff, 0xd590, 0xd885, 0xd992, 0xd6ac, 0xcf29, 0xc4d6, 0xb97d, 0xaee8, 0xa68b, 0xa07c, 0x9c79, 0x9a41, 0x9993, 0x0a25, 0x0a19, 
	0x09f7, 0x09c1, 0x097b, 0x0926, 0x08c6, 0x085c, 0x07ec, 0x0778, 0x0703, 0x068f, 0x061f, 0x05b6, 0x0555, 0x0501, 0x04ba, 0x0485, 
	0x0463, 0x0457, 0xd991, 0xd979, 0xd935, 0xd8cb, 0xd83f, 0xd797, 0xd6d7, 0xd606, 0xd527, 0xd441, 0xd358, 0xd271, 0xd193, 0xd0c1, 
	0xd002, 0xcf59, 0xcecd, 0xce63, 0xce1f, 0xce08, 0xe78a, 0xe7a0, 0xe7de, 0xe841, 0xe8c3, 0xe95f, 0xea10, 0xead2, 0xeba1, 0xec76, 
	0xed4e, 0xee23, 0xeef2, 0xefb4, 0xf065, 0xf101, 0xf183, 0xf1e6, 0xf224, 0xf23a, 0xffff, 0xff99, 0xfe85, 0xfcf1, 0xfb0a, 0xf8fe, 
	0xf6fb, 0xf52e, 0xf3c4, 0xf2ec, 0xf277, 0xf21a, 0xf1d2, 0xf19c, 0xf174, 0xf15a, 0xf14a, 0xf142, 0xf13f, 0xf13f, 0xffff, 0x007d, 
	0x01cf, 0x03c0, 0x061a, 0x08a6, 0x0b2e, 0x0d7b, 0x0f56, 0x108b, 0x1145, 0x11da, 0x124e, 0x12a5, 0x12e4, 0x130e, 0x1327, 0x1334, 
	0x1339, 0x133a, 0x0000, 0xffef, 0xffc4, 0xff84, 0xff36, 0xfee1, 0xfe8b, 0xfe3b, 0xfdf7, 0xfdc7, 0xfda7, 0xfd8c, 0xfd78, 0xfd69, 
	0xfd5e, 0xfd56, 0xfd52, 0xfd50, 0xfd4f, 0xfd4f, };

JointIndex gTidoSkelHammeringAnimJointIndices[16] = {
	{ 0x0000, 0x0001, 0x0002, },
	{ 0x0003, 0x0004, 0x0003, },
	{ 0x0000, 0x0005, 0x0006, },
	{ 0x0007, 0x0008, 0x0009, },
	{ 0x0000, 0x0000, 0x000a, },
	{ 0x0000, 0x000b, 0x0006, },
	{ 0x000c, 0x000d, 0x0009, },
	{ 0x0000, 0x0000, 0x000a, },
	{ 0x0000, 0x0000, 0x000e, },
	{ 0x000f, 0x0010, 0x0011, },
	{ 0x0012, 0x0013, 0x0014, },
	{ 0x0015, 0x0016, 0x0017, },
	{ 0x001a, 0x0018, 0x0000, },
	{ 0x002e, 0x0042, 0x0056, },
	{ 0x006a, 0x007e, 0x0092, },
	{ 0x0000, 0x0000, 0x0019, },
};

AnimationHeader gTidoSkelHammeringAnim = { { 20 }, gTidoSkelHammeringAnimFrameData, gTidoSkelHammeringAnimJointIndices, 26 };

