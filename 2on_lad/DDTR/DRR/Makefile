
all: ./Makefile_binaries/drr_sll_sll ./Makefile_binaries/drr_sll_dll ./Makefile_binaries/drr_sll_dyn_arr ./Makefile_binaries/drr_dll_sll ./Makefile_binaries/drr_dll_dll ./Makefile_binaries/drr_dll_dyn_arr ./Makefile_binaries/drr_dyn_arr_sll ./Makefile_binaries/drr_dyn_arr_dll ./Makefile_binaries/drr_dyn_arr_dyn_arr

# EXECUTABLES
./Makefile_binaries/drr_sll_sll: drr_sll_sll.c
		gcc drr_sll_sll.c -o ./Makefile_binaries/drr_sll_sll -pthread -DSLL_CL -DSLL_PK -lcdsl -L./../synch_implementations -I./../synch_implementations -no-pie

./Makefile_binaries/drr_sll_dll: drr_sll_dll.c
		gcc drr_sll_dll.c -o ./Makefile_binaries/drr_sll_dll -pthread -DSLL_CL -DDLL_PK -lcdsl -L./../synch_implementations -I./../synch_implementations -no-pie

./Makefile_binaries/drr_sll_dyn_arr: drr_sll_dyn_arr.c
		gcc drr_sll_dyn_arr.c -o ./Makefile_binaries/drr_sll_dyn_arr -pthread -DSLL_CL -DDYN_ARR_PK -lcdsl -L./../synch_implementations -I./../synch_implementations -no-pie

./Makefile_binaries/drr_dll_sll: drr_dll_sll.c
		gcc drr_dll_sll.c -o ./Makefile_binaries/drr_dll_sll -pthread -DDLL_CL -DSLL_PK -lcdsl -L./../synch_implementations -I./../synch_implementations -no-pie

./Makefile_binaries/drr_dll_dll: drr_dll_dll.c
		gcc drr_dll_dll.c -o ./Makefile_binaries/drr_dll_dll -pthread -DDLL_CL -DDLL_PK -lcdsl -L./../synch_implementations -I./../synch_implementations -no-pie

./Makefile_binaries/drr_dll_dyn_arr: drr_dll_dyn_arr.c
		gcc drr_dll_dyn_arr.c -o ./Makefile_binaries/drr_dll_dyn_arr -pthread -DDLL_CL -DDYN_ARR_PK -lcdsl -L./../synch_implementations -I./../synch_implementations -no-pie

./Makefile_binaries/drr_dyn_arr_sll: drr_dyn_arr_sll.c
		gcc drr_dyn_arr_sll.c -o ./Makefile_binaries/drr_dyn_arr_sll -pthread -DYN_ARR_CL -DSLL_PK -lcdsl -L./../synch_implementations -I./../synch_implementations -no-pie

./Makefile_binaries/drr_dyn_arr_dll: drr_dyn_arr_dll.c
		gcc drr_dyn_arr_dll.c -o ./Makefile_binaries/drr_dyn_arr_dll -pthread -DYN_ARR_CL -DDLL_PK -lcdsl -L./../synch_implementations -I./../synch_implementations -no-pie

./Makefile_binaries/drr_dyn_arr_dyn_arr: drr_dyn_arr_dyn_arr.c
		gcc drr_dyn_arr_dyn_arr.c -o ./Makefile_binaries/drr_dyn_arr_dyn_arr -pthread -DYN_ARR_CL -DDYN_ARR_PK -lcdsl -L./../synch_implementations -I./../synch_implementations -no-pie

# CLEANS
clean:
	rm *.o

clean_all:
	rm *.o DRR_SLL_SLL DRR_SLL_DLL DRR_SLL_DYN_ARR DRR_DLL_SLL DRR_DLL_DLL DRR_DLL_DYN_ARR DRR_DYN_ARR_SLL DRR_DYN_ARR_DLL DRR_DYN_ARR_DYN_ARR