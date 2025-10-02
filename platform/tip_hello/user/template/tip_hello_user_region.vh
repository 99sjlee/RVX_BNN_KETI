/*****************/
/* Custom Region */
/*****************/

// wire clk_system;
// wire clk_core;
// wire clk_system_external;
// wire clk_system_debug;
// wire clk_local_access;
// wire clk_process_000;
// wire clk_dram_if;
// wire clk_dram_sys;
// wire clk_dram_ref;
// wire clk_noc;
// wire gclk_system;
// wire gclk_core;
// wire gclk_system_external;
// wire gclk_system_debug;
// wire gclk_local_access;
// wire gclk_process_000;
// wire gclk_noc;
// wire tick_1us;
// wire tick_62d5ms;
// wire tick_gpio;
// wire spi_common_sclk;
// wire spi_common_sdq0;
// wire global_rstnn;
// wire global_rstpp;
// wire [(6)-1:0] rstnn_seqeunce;
// wire [(6)-1:0] rstpp_seqeunce;
// wire rstnn_user;
// wire rstpp_user;
// wire U_BNN_TOP_slave_clk;
// wire U_BNN_TOP_slave_rstnn;
// wire U_BNN_TOP_slave_rpsel;
// wire U_BNN_TOP_slave_rpenable;
// wire U_BNN_TOP_slave_rpwrite;
// wire [(32)-1:0] U_BNN_TOP_slave_rpaddr;
// wire [(32)-1:0] U_BNN_TOP_slave_rpwdata;
// wire U_BNN_TOP_slave_rpready;
// wire [(32)-1:0] U_BNN_TOP_slave_rprdata;
// wire U_BNN_TOP_slave_rpslverr;
// wire U_BNN_TOP_master_clk;
// wire U_BNN_TOP_master_rstnn;
// wire U_BNN_TOP_master_sxawready;
// wire U_BNN_TOP_master_sxawvalid;
// wire [(32)-1:0] U_BNN_TOP_master_sxawaddr;
// wire [(2)-1:0] U_BNN_TOP_master_sxawid;
// wire [(8)-1:0] U_BNN_TOP_master_sxawlen;
// wire [(3)-1:0] U_BNN_TOP_master_sxawsize;
// wire [(2)-1:0] U_BNN_TOP_master_sxawburst;
// wire U_BNN_TOP_master_sxwready;
// wire U_BNN_TOP_master_sxwvalid;
// wire [(2)-1:0] U_BNN_TOP_master_sxwid;
// wire [(64)-1:0] U_BNN_TOP_master_sxwdata;
// wire [(64/8)-1:0] U_BNN_TOP_master_sxwstrb;
// wire U_BNN_TOP_master_sxwlast;
// wire U_BNN_TOP_master_sxbready;
// wire U_BNN_TOP_master_sxbvalid;
// wire [(2)-1:0] U_BNN_TOP_master_sxbid;
// wire [(2)-1:0] U_BNN_TOP_master_sxbresp;
// wire U_BNN_TOP_master_sxarready;
// wire U_BNN_TOP_master_sxarvalid;
// wire [(32)-1:0] U_BNN_TOP_master_sxaraddr;
// wire [(2)-1:0] U_BNN_TOP_master_sxarid;
// wire [(8)-1:0] U_BNN_TOP_master_sxarlen;
// wire [(3)-1:0] U_BNN_TOP_master_sxarsize;
// wire [(2)-1:0] U_BNN_TOP_master_sxarburst;
// wire U_BNN_TOP_master_sxrready;
// wire U_BNN_TOP_master_sxrvalid;
// wire [(2)-1:0] U_BNN_TOP_master_sxrid;
// wire [(64)-1:0] U_BNN_TOP_master_sxrdata;
// wire U_BNN_TOP_master_sxrlast;
// wire [(2)-1:0] U_BNN_TOP_master_sxrresp;

/* DO NOT MODIFY THE ABOVE */
/* MUST MODIFY THE BELOW   */


/*
USER_IP
#(
	.SIZE_OF_MEMORYMAP((32'h 1000)),
	.BW_ADDR(32),
	.BW_DATA(32)
)
U_BNN_TOP_slave
(
	.clk(U_BNN_TOP_slave_clk),
	.rstnn(U_BNN_TOP_slave_rstnn),
	.rpsel(U_BNN_TOP_slave_rpsel),
	.rpenable(U_BNN_TOP_slave_rpenable),
	.rpwrite(U_BNN_TOP_slave_rpwrite),
	.rpaddr(U_BNN_TOP_slave_rpaddr),
	.rpwdata(U_BNN_TOP_slave_rpwdata),
	.rpready(U_BNN_TOP_slave_rpready),
	.rprdata(U_BNN_TOP_slave_rprdata),
	.rpslverr(U_BNN_TOP_slave_rpslverr)
);
*/
//assign `NOT_CONNECT = U_BNN_TOP_slave_clk;
//assign `NOT_CONNECT = U_BNN_TOP_slave_rstnn;
//assign `NOT_CONNECT = U_BNN_TOP_slave_rpsel;
//assign `NOT_CONNECT = U_BNN_TOP_slave_rpenable;
//assign `NOT_CONNECT = U_BNN_TOP_slave_rpwrite;
//assign `NOT_CONNECT = U_BNN_TOP_slave_rpaddr;
//assign `NOT_CONNECT = U_BNN_TOP_slave_rpwdata;
assign U_BNN_TOP_slave_rpready = 0;
assign U_BNN_TOP_slave_rprdata = 0;
assign U_BNN_TOP_slave_rpslverr = 0;

/*
USER_IP
#(
	.BW_ADDR(32),
	.BW_DATA(64),
	.BW_AXI_TID(2)
)
U_BNN_TOP_master
(
	.clk(U_BNN_TOP_master_clk),
	.rstnn(U_BNN_TOP_master_rstnn),
	.sxawready(U_BNN_TOP_master_sxawready),
	.sxawvalid(U_BNN_TOP_master_sxawvalid),
	.sxawaddr(U_BNN_TOP_master_sxawaddr),
	.sxawid(U_BNN_TOP_master_sxawid),
	.sxawlen(U_BNN_TOP_master_sxawlen),
	.sxawsize(U_BNN_TOP_master_sxawsize),
	.sxawburst(U_BNN_TOP_master_sxawburst),
	.sxwready(U_BNN_TOP_master_sxwready),
	.sxwvalid(U_BNN_TOP_master_sxwvalid),
	.sxwid(U_BNN_TOP_master_sxwid),
	.sxwdata(U_BNN_TOP_master_sxwdata),
	.sxwstrb(U_BNN_TOP_master_sxwstrb),
	.sxwlast(U_BNN_TOP_master_sxwlast),
	.sxbready(U_BNN_TOP_master_sxbready),
	.sxbvalid(U_BNN_TOP_master_sxbvalid),
	.sxbid(U_BNN_TOP_master_sxbid),
	.sxbresp(U_BNN_TOP_master_sxbresp),
	.sxarready(U_BNN_TOP_master_sxarready),
	.sxarvalid(U_BNN_TOP_master_sxarvalid),
	.sxaraddr(U_BNN_TOP_master_sxaraddr),
	.sxarid(U_BNN_TOP_master_sxarid),
	.sxarlen(U_BNN_TOP_master_sxarlen),
	.sxarsize(U_BNN_TOP_master_sxarsize),
	.sxarburst(U_BNN_TOP_master_sxarburst),
	.sxrready(U_BNN_TOP_master_sxrready),
	.sxrvalid(U_BNN_TOP_master_sxrvalid),
	.sxrid(U_BNN_TOP_master_sxrid),
	.sxrdata(U_BNN_TOP_master_sxrdata),
	.sxrlast(U_BNN_TOP_master_sxrlast),
	.sxrresp(U_BNN_TOP_master_sxrresp)
);
*/
//assign `NOT_CONNECT = U_BNN_TOP_master_clk;
//assign `NOT_CONNECT = U_BNN_TOP_master_rstnn;
//assign `NOT_CONNECT = U_BNN_TOP_master_sxawready;
assign U_BNN_TOP_master_sxawvalid = 0;
assign U_BNN_TOP_master_sxawaddr = 0;
assign U_BNN_TOP_master_sxawid = 0;
assign U_BNN_TOP_master_sxawlen = 0;
assign U_BNN_TOP_master_sxawsize = 0;
assign U_BNN_TOP_master_sxawburst = 0;
//assign `NOT_CONNECT = U_BNN_TOP_master_sxwready;
assign U_BNN_TOP_master_sxwvalid = 0;
assign U_BNN_TOP_master_sxwid = 0;
assign U_BNN_TOP_master_sxwdata = 0;
assign U_BNN_TOP_master_sxwstrb = 0;
assign U_BNN_TOP_master_sxwlast = 0;
assign U_BNN_TOP_master_sxbready = 0;
//assign `NOT_CONNECT = U_BNN_TOP_master_sxbvalid;
//assign `NOT_CONNECT = U_BNN_TOP_master_sxbid;
//assign `NOT_CONNECT = U_BNN_TOP_master_sxbresp;
//assign `NOT_CONNECT = U_BNN_TOP_master_sxarready;
assign U_BNN_TOP_master_sxarvalid = 0;
assign U_BNN_TOP_master_sxaraddr = 0;
assign U_BNN_TOP_master_sxarid = 0;
assign U_BNN_TOP_master_sxarlen = 0;
assign U_BNN_TOP_master_sxarsize = 0;
assign U_BNN_TOP_master_sxarburst = 0;
assign U_BNN_TOP_master_sxrready = 0;
//assign `NOT_CONNECT = U_BNN_TOP_master_sxrvalid;
//assign `NOT_CONNECT = U_BNN_TOP_master_sxrid;
//assign `NOT_CONNECT = U_BNN_TOP_master_sxrdata;
//assign `NOT_CONNECT = U_BNN_TOP_master_sxrlast;
//assign `NOT_CONNECT = U_BNN_TOP_master_sxrresp;

