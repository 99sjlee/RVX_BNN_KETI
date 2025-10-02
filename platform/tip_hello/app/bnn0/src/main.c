#include "platform_info.h"
#include "ervp_printf.h"
#include "ervp_reg_util.h"
#include "mem_0_4.h"
#include "sw_0_4.h"
#include "inst.h"
#include "ervp_core_id.h"
#include "ervp_variable_allocation.h"
#include "ervp_memory_util.h"
#include "ervp_platform_api.h"
#include "ervp_fakefile.h"
#include "ervp_real_clock.h"
#include "ervp_variable_allocation.h"
#include "ervp_mcom_input.h"

#define TEST_MEMORY_SIZE  (I_USER_DDR4_SIZE)
#define TEST_SIZE TEST_MEMORY_SIZE

#define HAS(s, sub) (strstr((s), (sub)) != NULL)

static inline unsigned int get_bnn_apb_addr(unsigned int offset)
{
	return (U_BNN_TOP_SLAVE_SLAVE_BASEADDR+offset);
}

bool apb_setting(uint16_t iter, inst_param_t sc_pr, uint64_t hw_mem_addr){
	if(iter == 0){
		REG32(get_bnn_apb_addr(0x7F8)) = sc_pr.STATE_UPDATE_CONFIG[0];
	}
	else {
		REG32(get_bnn_apb_addr(0x7F8)) = sc_pr.STATE_UPDATE_CONFIG[1];
	}

	REG32(get_bnn_apb_addr(0x68)) = hw_mem_addr;

	REG32(get_bnn_apb_addr(0x10)) = sc_pr.DRAM_BIFMAPOFFSET[0];
	REG32(get_bnn_apb_addr(0x18)) = sc_pr.DRAM_BIFMAPOFFSET[1];
	REG32(get_bnn_apb_addr(0x20)) = sc_pr.DRAM_BIFMAPOFFSET[2];

	REG32(get_bnn_apb_addr(0x200)) = sc_pr.DRAM_FIFMAPOFFSET[0] + iter*32*(sc_pr.DRAM_FIOFMAPLENGTH/4);
	REG32(get_bnn_apb_addr(0x208)) = sc_pr.DRAM_FIFMAPOFFSET[1] + iter*32*(sc_pr.DRAM_FIOFMAPLENGTH/4);
	REG32(get_bnn_apb_addr(0x210)) = sc_pr.DRAM_FIFMAPOFFSET[2] + iter*32*(sc_pr.DRAM_FIOFMAPLENGTH/4);
	REG32(get_bnn_apb_addr(0x218)) = sc_pr.DRAM_FIFMAPOFFSET[3] + iter*32*(sc_pr.DRAM_FIOFMAPLENGTH/4);
	REG32(get_bnn_apb_addr(0x220)) = sc_pr.DRAM_FIFMAPOFFSET[4] + iter*32*(sc_pr.DRAM_FIOFMAPLENGTH/4);
	REG32(get_bnn_apb_addr(0x228)) = sc_pr.DRAM_FIFMAPOFFSET[5] + iter*32*(sc_pr.DRAM_FIOFMAPLENGTH/4);
	REG32(get_bnn_apb_addr(0x230)) = sc_pr.DRAM_FIFMAPOFFSET[6] + iter*32*(sc_pr.DRAM_FIOFMAPLENGTH/4);
	REG32(get_bnn_apb_addr(0x238)) = sc_pr.DRAM_FIFMAPOFFSET[7] + iter*32*(sc_pr.DRAM_FIOFMAPLENGTH/4);

	REG32(get_bnn_apb_addr(0x240)) = sc_pr.DRAM_FOFMAPOFFSET[0] + iter*32*(sc_pr.DRAM_FIOFMAPLENGTH/4);;
	REG32(get_bnn_apb_addr(0x248)) = sc_pr.DRAM_FOFMAPOFFSET[1] + iter*32*(sc_pr.DRAM_FIOFMAPLENGTH/4);;
	REG32(get_bnn_apb_addr(0x250)) = sc_pr.DRAM_FOFMAPOFFSET[2] + iter*32*(sc_pr.DRAM_FIOFMAPLENGTH/4);;
	REG32(get_bnn_apb_addr(0x258)) = sc_pr.DRAM_FOFMAPOFFSET[3] + iter*32*(sc_pr.DRAM_FIOFMAPLENGTH/4);;
	REG32(get_bnn_apb_addr(0x260)) = sc_pr.DRAM_FOFMAPOFFSET[4] + iter*32*(sc_pr.DRAM_FIOFMAPLENGTH/4);;
	REG32(get_bnn_apb_addr(0x268)) = sc_pr.DRAM_FOFMAPOFFSET[5] + iter*32*(sc_pr.DRAM_FIOFMAPLENGTH/4);;
	REG32(get_bnn_apb_addr(0x270)) = sc_pr.DRAM_FOFMAPOFFSET[6] + iter*32*(sc_pr.DRAM_FIOFMAPLENGTH/4);;
	REG32(get_bnn_apb_addr(0x278)) = sc_pr.DRAM_FOFMAPOFFSET[7] + iter*32*(sc_pr.DRAM_FIOFMAPLENGTH/4);;

	REG32(get_bnn_apb_addr(0x28)) = sc_pr.DRAM_BIFMAPLENGTH;

	REG32(get_bnn_apb_addr(0x2a8)) = 0x04;

	REG32(get_bnn_apb_addr(0x30)) = sc_pr.DRAM_PEA_BWEIGHTOFFSET[0] + iter*(sc_pr.DRAM_BWEIGHTLENGTH[0] << 3);
	REG32(get_bnn_apb_addr(0x38)) = sc_pr.DRAM_PEA_BWEIGHTOFFSET[1] + iter*(sc_pr.DRAM_BWEIGHTLENGTH[0] << 3);
	REG32(get_bnn_apb_addr(0x40)) = sc_pr.DRAM_PEA_BWEIGHTOFFSET[2] + iter*(sc_pr.DRAM_BWEIGHTLENGTH[0] << 3);
	REG32(get_bnn_apb_addr(0x48)) = sc_pr.DRAM_BWEIGHTLENGTH[0];

	REG32(get_bnn_apb_addr(0x50)) = sc_pr.DRAM_PEA_ALPHAOFFSET + iter*(8 << 3);
	REG32(get_bnn_apb_addr(0x58)) = sc_pr.DRAM_PEA_BETAOFFSET + iter*(8 << 3);
	REG32(get_bnn_apb_addr(0x60)) = sc_pr.DRAM_CLENGTH[0];

	REG32(get_bnn_apb_addr(0x70)) = sc_pr.DRAM_FIOFMAPLENGTH;

	REG32(get_bnn_apb_addr(0x280)) = sc_pr.DRAM_CTRL_HEIGHT_LEN;

	REG32(get_bnn_apb_addr(0x78)) = 0x03;

	REG32(get_bnn_apb_addr(0x80)) = 0x03;

	REG32(get_bnn_apb_addr(0x88)) = 0x03;

	REG32(get_bnn_apb_addr(0x90)) = 0x03;

	REG32(get_bnn_apb_addr(0x850)) = sc_pr.FOFMAP_ADDR_OFFSET_SHIFTED;
	REG32(get_bnn_apb_addr(0x858)) = sc_pr.FOFMAP_ADDR_OFFSET_SHIFTED;
	REG32(get_bnn_apb_addr(0x860)) = sc_pr.FOFMAP_ADDR_OFFSET_SHIFTED;
	REG32(get_bnn_apb_addr(0x868)) = sc_pr.FOFMAP_ADDR_OFFSET_SHIFTED;
	REG32(get_bnn_apb_addr(0x870)) = sc_pr.FOFMAP_ADDR_OFFSET_SHIFTED;
	REG32(get_bnn_apb_addr(0x878)) = sc_pr.FOFMAP_ADDR_OFFSET_SHIFTED;
	REG32(get_bnn_apb_addr(0x880)) = sc_pr.FOFMAP_ADDR_OFFSET_SHIFTED;
	REG32(get_bnn_apb_addr(0x888)) = sc_pr.FOFMAP_ADDR_OFFSET_SHIFTED;

	REG32(get_bnn_apb_addr(0x948)) = 0;
	REG32(get_bnn_apb_addr(0x950)) = sc_pr.PW_W_ADDR_OFFSET;
	REG32(get_bnn_apb_addr(0x958)) = 0;
	REG32(get_bnn_apb_addr(0x960)) = sc_pr.PW_C_ADDR_OFFSET;

	REG32(get_bnn_apb_addr(0x8d0)) = sc_pr.STRIDE_LENGTH;
	REG32(get_bnn_apb_addr(0x8d8)) = sc_pr.IFMAP_WIDTH_LENGTH;
	REG32(get_bnn_apb_addr(0x8e0)) = sc_pr.IFMAP_HEIGHT_LENGTH;
	REG32(get_bnn_apb_addr(0x8e8)) = sc_pr.KERNEL_CHANNEL_RANGE;

	REG32(get_bnn_apb_addr(0x8f0)) = sc_pr.IFMAP_CTRL_HEIGHT;
	REG32(get_bnn_apb_addr(0x8f8)) = sc_pr.IFMAP_CTRL_HEIGHT;

	REG32(get_bnn_apb_addr(0x900)) = sc_pr.KERNEL_SIDE_LENGTH;
	REG32(get_bnn_apb_addr(0x908)) = sc_pr.KERNEL_SIDE_LENGTH;
	REG32(get_bnn_apb_addr(0x910)) = sc_pr.KERNEL_CHANNEL_RANGE;
	
	REG32(get_bnn_apb_addr(0x918)) = 0xFFFFFFFF;

	REG32(get_bnn_apb_addr(0x920)) = sc_pr.OFMAP_CHANNEL_RANGE;

	REG32(get_bnn_apb_addr(0x928)) = 7;
	REG32(get_bnn_apb_addr(0x930)) = 7;

	REG32(get_bnn_apb_addr(0x938)) = sc_pr.FOFMAP_ADDR_OFFSET;

	REG32(get_bnn_apb_addr(0x940)) = sc_pr.LAYER_OPS_TYPE;

	REG32(get_bnn_apb_addr(0x948)) = sc_pr.CONV_W_ADDR_OFFSET;
	REG32(get_bnn_apb_addr(0x950)) = sc_pr.PW_W_ADDR_OFFSET;
	REG32(get_bnn_apb_addr(0x958)) = sc_pr.CONV_C_ADDR_OFFSET;
	REG32(get_bnn_apb_addr(0x960)) = sc_pr.PW_C_ADDR_OFFSET;

	REG32(get_bnn_apb_addr(0x968)) = 4*(iter + 1);

	REG32(get_bnn_apb_addr(0x970)) = 1 << sc_pr.DIVIDE_FACTOR;

	REG32(get_bnn_apb_addr(0x978)) = 7;
	REG32(get_bnn_apb_addr(0x980)) = 7;
	REG32(get_bnn_apb_addr(0x988)) = 0;
	REG32(get_bnn_apb_addr(0x990)) = 0;
	REG32(get_bnn_apb_addr(0x998)) = 0;
	REG32(get_bnn_apb_addr(0x9a0)) = 0;
	REG32(get_bnn_apb_addr(0x9a8)) = 0;
	REG32(get_bnn_apb_addr(0x9b0)) = 0;

	return true;
}

int run_bnn_ip(uint16_t iter, uint8_t iter_last){
	uint8_t r_cr0 = 0;
	if(iter != 0){
		uint32_t r_busy;
		uint32_t PADDR_CR0 = REG32(get_bnn_apb_addr(0x7F0));
		r_busy = (PADDR_CR0 >> 2) & 0x1;
		do {
			PADDR_CR0 = REG32(get_bnn_apb_addr(0x7F0));
			r_busy = (PADDR_CR0 >> 2) & 0x1;
		} while (r_busy == 1);
		REG32(get_bnn_apb_addr(0x7F0)) = 0x40;
	}

	r_cr0 |= 0x00000002;
	if (iter == iter_last - 1) {
		r_cr0 |= 0x00000010;
	}
	
	REG32(get_bnn_apb_addr(0x7F0)) = r_cr0;
	REG32(get_bnn_apb_addr(0x08)) = 0x1;

	return 0;
}

#define INPUT_SIZE    (8 * 8 * 128)
#define OUTPUT_SIZE   (8 * 8 * 128)  
#define WEIGHTS_SIZE  (3 * 3 * 128 * 128)
#define BN_ALPHA_SIZE (128)
#define BN_BETA_SIZE  (128)
#define INPUT_PAD_SIZE  (10 * 10 * 128)

int run_bnn_sw(){
	void *sw_mem_addr = (void *)(I_USER_DDR4_BASEADDR);
	uint64_t *current_addr = (uint64_t *)sw_mem_addr;
	uint64_t *input = (uint64_t *)current_addr;
    current_addr += (uint64_t)INPUT_SIZE;
	// printf("After INPUT (+%llu): 0x%016llX\n", (uint64_t)INPUT_SIZE, (uint64_t)current_addr);
	uint64_t *weights = (uint64_t *)current_addr;
    current_addr += (uint64_t)WEIGHTS_SIZE;
	// printf("After WEIGHTS (+%llu): 0x%016llX\n", (uint64_t)WEIGHTS_SIZE, (uint64_t)current_addr);
	uint64_t *bn_alpha = (uint64_t *)current_addr;
    current_addr += (uint64_t)BN_ALPHA_SIZE;
	// printf("After BN_ALPHA (+%llu): 0x%016llX\n", (uint64_t)BN_ALPHA_SIZE, (uint64_t)current_addr);
    uint64_t *bn_beta = (uint64_t *)current_addr;
    current_addr += (uint64_t)BN_BETA_SIZE;
	// printf("After BN_BETA (+%llu): 0x%016llX\n", (uint64_t)BN_BETA_SIZE, (uint64_t)current_addr);
	uint64_t *sinput = (uint64_t *)current_addr;
	current_addr += (uint64_t)INPUT_SIZE;
	uint64_t *input_pad = (uint64_t *)current_addr;
	current_addr += (uint64_t)INPUT_PAD_SIZE;

	uint64_t *output = (uint64_t *)current_addr;

	memcpy(input, sw_0_4, sizeof(sw_0_4));
	memcpy(weights, sw_w_0_4, sizeof(sw_w_0_4));
	memcpy(bn_alpha, sw_ba_0_4, sizeof(sw_ba_0_4));
	memcpy(bn_beta, sw_bb_0_4, sizeof(sw_bb_0_4));
	memcpy(sinput, sw_si_0_4, sizeof(sw_si_0_4));

	uint64_t sw_tick = get_real_clock_tick();
	uint16_t batch_size = 1;
	uint16_t H = 8, W = 8, C = 128;
    uint16_t K = 3;
    uint16_t F = 128;
    uint16_t S = 1;

	uint16_t out_h = 0;
	if ((S <= 0) | (H <= 0)){
		out_h = 0;
	}
	else{
		out_h = (H+S-1)/S;
	}
	uint16_t out_w = 0;
	if ((S <= 0) | (W <= 0)){
		out_w = 0;
	}
	else{
		out_w = (W+S-1)/S;
	}
	
	uint16_t pad_along_h = 0;
	uint16_t pad_along_w = 0;
	if ((out_h - 1) * S + K - H > 0) {
        pad_along_h = (out_h - 1) * S + K - H;
    }
	if ((out_w - 1) * S + K - W > 0) {
        pad_along_w = (out_w - 1) * S + K - W;
    }
	
	uint16_t pad_top = pad_along_h / 2;
	uint16_t pad_bottom = pad_along_h - pad_top;
	uint16_t pad_left = pad_along_w / 2;
	uint16_t pad_right = pad_along_w - pad_left;

	uint16_t padded_h = H + pad_top + pad_bottom;
    uint16_t padded_w = W + pad_left + pad_right;
	
	for (uint16_t h = 0; h < padded_h; h++) {
		for (uint16_t w = 0; w < padded_w; w++) {
			for (uint16_t c = 0; c < C; c++) {
				input_pad[h*padded_w*C + w*C + c] = 0;
			}
		}
	}

	for (uint16_t h = 0; h < H; h++) {
		for (uint16_t w = 0; w < W; w++) {
			for (uint16_t c = 0; c < C; c++) {
				input_pad[(h+pad_top)*padded_w*C + (w+pad_left)*C + c] = input[h*W*C + w*C + c];
			}
		}
	}

	for (uint16_t b = 0; b < batch_size; b++) {
        for (uint16_t f = 0; f < F; f++) {
            for (uint16_t i = 0; i < out_h; i++) {
                for (uint16_t j = 0; j < out_w; j++) {
                    uint64_t sum = 0;
                    
                    for (uint16_t kh = 0; kh < K; kh++) {
                        for (uint16_t kw = 0; kw < K; kw++) {
                            for (uint16_t c = 0; c < C; c++) {
                                uint16_t input_h = i * S + kh;
                                uint16_t input_w = j * S + kw;
                                
								int64_t input_val = (int64_t)input_pad[input_h*padded_w*C + input_w*C + c];
								int64_t weight_val = (int64_t)weights[kh*K*C*F + kw*C*F + c*F + f];
                                sum += input_val * weight_val;
                            }
                        }
                    }

					output[i*out_w*F + j*F + f] = ((int64_t)((sum*bn_alpha[f] + bn_beta[f]) + sinput[i*out_w*F + j*F + f]) >> 7);
                }
            }
        }
	}
	uint64_t sw_tick2 = get_real_clock_tick();
	uint64_t sw_total = sw_tick2-sw_tick;
	float sw_ms = (float)(sw_total) / 1000;
	printf("\nSW Total Tick %llu", sw_total);
	printf("\nSW Total Time (ms) %.3f", sw_ms);
	int all_are_equal = 1;
	int mcmp = memory_compare(output, sw_o_0_4, sizeof(sw_o_0_4), 0);
	all_are_equal &= mcmp;
	if(all_are_equal){
		printf("\nSW RESULT all correct");
	}
	else{
		printf("\nSW RESULT some incorrect");
		for (size_t i = 0; i < 10; ++i){
			if(sw_o_0_4[i] != output[i]) {
				printf("\nidx %zu  EXPECT 0x%016llX  READ 0x%016llX", i, sw_o_0_4[i], output[i]);
			}
		}
	}
	
	return 0;
}

int main() {
	printf("\nSHORTCUT 0 TYPE ACCELERATOR\n");
  printf("\nBNN acceleration\n");

	void *hw_mem_addr = (void*)(I_USER_DDR4_BASEADDR);
	// uint64_t *hw_mem_addr = (uint64_t *)mem_base_addr;
	// hw_mem_addr += (uint64_t)INPUT_SIZE+(uint64_t)OUTPUT_SIZE+(uint64_t)WEIGHTS_SIZE+(uint64_t)BN_ALPHA_SIZE+(uint64_t)BN_BETA_SIZE+(uint64_t)INPUT_PAD_SIZE;
	void *output_addr = (void *)(I_USER_DDR4_BASEADDR + 0x100000);
	const uint64_t *rd = (const uint64_t *)output_addr;
	
  printf("\nEnter any charcater\n");

  getc_from_mcom(); // input any key

  printf("\nStart BNN Software\n");

	//sw
	run_bnn_sw();

  printf("\nStart BNN Hardware\n");

	//hw
	int all_are_equal = 1;
	int single_test_size = sizeof(mem_0_4);
	memcpy(hw_mem_addr, mem_0_4, single_test_size);
	flush_cache();
	inst_param_t sc_pr;
	if (!inst_fill("shortcut0_4", &sc_pr)) {
		printf("inst_fill_params failed\n");
		return 1;
	}

	uint64_t hw_total_tick = 0;
	for (uint16_t iter=0; iter<sc_pr.iter_last; iter++){
		//param setting
		apb_setting(iter, sc_pr, (uint64_t)hw_mem_addr);
		//hw
		uint64_t hw_tick = get_real_clock_tick();
		run_bnn_ip(iter, sc_pr.iter_last);
		uint64_t hw_tick2 = get_real_clock_tick();
		hw_total_tick += (hw_tick2 - hw_tick);
	}
	float ms, ms2;
	ms2 = (float)(hw_total_tick) / 1000;

	printf("\nHW Total Tick %llu", hw_total_tick);
	printf("\nHW Total Time (ms) %.3f", ms2);

	int output_matched = 1;
	int output_single_test_size = sizeof(ofmap_0_4);
	int omcmp = memory_compare(output_addr, ofmap_0_4, output_single_test_size, 0);
	output_matched &= omcmp;
    if(output_matched){
      	printf("\nHW RESULT all correct");
	}
    else {
      	printf("\nHW RESULT some incorrect");
		for (size_t i = 0; i < 5; ++i)
			printf("\nidx %zu  EXPECT 0x%016llX  READ 0x%016llX",
				i, ofmap_0_4[i], rd[i]);
			}
	return 0;
}
