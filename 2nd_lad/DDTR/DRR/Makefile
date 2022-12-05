
all: ./binaries/drr_sll_sll ./binaries/drr_sll_dll ./binaries/drr_sll_dyn_arr ./binaries/drr_dll_sll ./binaries/drr_dll_dll ./binaries/drr_dll_dyn_arr ./binaries/drr_dyn_arr_sll ./binaries/drr_dyn_arr_dll ./binaries/drr_dyn_arr_dyn_arr

# EXECUTABLES
./binaries/drr_sll_sll: drr.c
		gcc drr.c -o ./binaries/drr_sll_sll -pthread -DSLL_CL -DSLL_PK -lcdsl -L./../synch_implementations -I./../synch_implementations -no-pie

./binaries/drr_sll_dll: drr.c
		gcc drr.c -o ./binaries/drr_sll_dll -pthread -DSLL_CL -DDLL_PK -lcdsl -L./../synch_implementations -I./../synch_implementations -no-pie

./binaries/drr_sll_dyn_arr: drr.c
		gcc drr.c -o ./binaries/drr_sll_dyn_arr -pthread -DSLL_CL -DDYN_ARR_PK -lcdsl -L./../synch_implementations -I./../synch_implementations -no-pie

./binaries/drr_dll_sll: drr.c
		gcc drr.c -o ./binaries/drr_dll_sll -pthread -DDLL_CL -DSLL_PK -lcdsl -L./../synch_implementations -I./../synch_implementations -no-pie

./binaries/drr_dll_dll: drr.c
		gcc drr.c -o ./binaries/drr_dll_dll -pthread -DDLL_CL -DDLL_PK -lcdsl -L./../synch_implementations -I./../synch_implementations -no-pie

./binaries/drr_dll_dyn_arr: drr.c
		gcc drr.c -o ./binaries/drr_dll_dyn_arr -pthread -DDLL_CL -DDYN_ARR_PK -lcdsl -L./../synch_implementations -I./../synch_implementations -no-pie

./binaries/drr_dyn_arr_sll: drr.c
		gcc drr.c -o ./binaries/drr_dyn_arr_sll -pthread -DDYN_ARR_CL -DSLL_PK -lcdsl -L./../synch_implementations -I./../synch_implementations -no-pie

./binaries/drr_dyn_arr_dll: drr.c
		gcc drr.c -o ./binaries/drr_dyn_arr_dll -pthread -DDYN_ARR_CL -DDLL_PK -lcdsl -L./../synch_implementations -I./../synch_implementations -no-pie

./binaries/drr_dyn_arr_dyn_arr: drr.c
		gcc drr.c -o ./binaries/drr_dyn_arr_dyn_arr -pthread -DDYN_ARR_CL -DDYN_ARR_PK -lcdsl -L./../synch_implementations -I./../synch_implementations -no-pie

# CLEANS
clean:
	rm *.o

clean_all:
	rm *.o binaries/drr_sll_sll binaries/drr_sll_dll binaries/drr_sll_dyn_arr binaries/drr_dll_sll binaries/drr_dll_dll binaries/drr_dll_dyn_arr binaries/drr_dyn_arr_sll binaries/drr_dyn_arr_dll binaries/drr_dyn_arr_dyn_arr