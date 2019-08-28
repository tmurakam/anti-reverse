#!/bin/sh
#sudo capsh --drop=cap_sys_ptrace -- -c "capsh --print"
sudo capsh --drop=cap_sys_ptrace -- -c ./anti_reverse
