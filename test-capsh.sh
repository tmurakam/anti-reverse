#!/bin/sh
sudo capsh --drop=cap_sys_ptrace -- -c "capsh --print && ./anti_reverse"
