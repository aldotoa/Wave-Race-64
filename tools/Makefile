#*************************************************************
#
#	A very simple Makefile for Copymask and other tools
#
#	TODO
#
#*************************************************************




IDO_RECOMP_URL := https://github.com/decompals/ido-static-recomp
IDO_RECOMP_REV := d5aec59932034b8a20f23f471297a55c45dcbc45
TORCH_URL      := https://github.com/HarbourMasters/Torch

default:# torch
	@$(CC) n64crc.c -o n64crc
	@test -f ido-static-recomp/Makefile || { rm -rf ido-static-recomp && \
		git clone $(IDO_RECOMP_URL) ido-static-recomp && \
		git -C ido-static-recomp checkout -q $(IDO_RECOMP_REV); }
	@make  -C ido-static-recomp/ setup
	@make  -C ido-static-recomp/ VERSION=5.3
	@printf "done\n"

torch:
	@echo "Building torch..."
	@test -d Torch/.git || git clone --recursive $(TORCH_URL) Torch
	$(MAKE) -C Torch type=release -j$(N_THREADS)

clean:
	rm n64crc
