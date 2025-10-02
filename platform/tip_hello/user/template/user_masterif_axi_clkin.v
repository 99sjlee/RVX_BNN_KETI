// ****************************************************************************
// ****************************************************************************
// Copyright SoC Design Research Group, All rights reserved.
// Electronics and Telecommunications Research Institute (ETRI)
// 
// THESE DOCUMENTS CONTAIN CONFIDENTIAL INFORMATION AND KNOWLEDGE
// WHICH IS THE PROPERTY OF ETRI. NO PART OF THIS PUBLICATION IS
// TO BE USED FOR ANY OTHER PURPOSE, AND THESE ARE NOT TO BE
// REPRODUCED, COPIED, DISCLOSED, TRANSMITTED, STORED IN A RETRIEVAL
// SYSTEM OR TRANSLATED INTO ANY OTHER HUMAN OR COMPUTER LANGUAGE,
// IN ANY FORM, BY ANY MEANS, IN WHOLE OR IN PART, WITHOUT THE
// COMPLETE PRIOR WRITTEN PERMISSION OF ETRI.
// ****************************************************************************
// 2025-08-05
// Kyuseung Han (han@etri.re.kr)
// ****************************************************************************
// ****************************************************************************


module USER_MASTERIF_AXI_CLKIN
(
	clk,
	rstnn,
	sxawready,
	sxawvalid,
	sxawaddr,
	sxawid,
	sxawlen,
	sxawsize,
	sxawburst,
	sxwready,
	sxwvalid,
	sxwid,
	sxwdata,
	sxwstrb,
	sxwlast,
	sxbready,
	sxbvalid,
	sxbid,
	sxbresp,
	sxarready,
	sxarvalid,
	sxaraddr,
	sxarid,
	sxarlen,
	sxarsize,
	sxarburst,
	sxrready,
	sxrvalid,
	sxrid,
	sxrdata,
	sxrlast,
	sxrresp
);

parameter BW_ADDR = 1;
parameter BW_DATA = 1;
parameter BW_AXI_TID = 1;

input wire clk;
input wire rstnn;
input wire sxawready;
output wire sxawvalid;
output wire [(BW_ADDR)-1:0] sxawaddr;
output wire [(BW_AXI_TID)-1:0] sxawid;
output wire [(8)-1:0] sxawlen;
output wire [(3)-1:0] sxawsize;
output wire [(2)-1:0] sxawburst;
input wire sxwready;
output wire sxwvalid;
output wire [(BW_AXI_TID)-1:0] sxwid;
output wire [(BW_DATA)-1:0] sxwdata;
output wire [(BW_DATA/8)-1:0] sxwstrb;
output wire sxwlast;
output wire sxbready;
input wire sxbvalid;
input wire [(BW_AXI_TID)-1:0] sxbid;
input wire [(2)-1:0] sxbresp;
input wire sxarready;
output wire sxarvalid;
output wire [(BW_ADDR)-1:0] sxaraddr;
output wire [(BW_AXI_TID)-1:0] sxarid;
output wire [(8)-1:0] sxarlen;
output wire [(3)-1:0] sxarsize;
output wire [(2)-1:0] sxarburst;
output wire sxrready;
input wire sxrvalid;
input wire [(BW_AXI_TID)-1:0] sxrid;
input wire [(BW_DATA)-1:0] sxrdata;
input wire sxrlast;
input wire [(2)-1:0] sxrresp;






endmodule