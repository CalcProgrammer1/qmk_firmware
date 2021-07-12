import subprocess
import os

BOARDS = ['redragon/k552/rev1', 'redragon/k552/rev2', 'redragon/k530', 'redragon/k556', 'redragon/k580', 'keychron/c1', 'keychron/k2', 'keychron/k4', 'keychron/k6', 'keychron/k8', 'ajazz/ak33/rev1', 'ajazz/ak33/rev2', 'smartduck/xs61', 'spcgear/gk530', 'spcgear/gk540', 'sharkoon/sgk3', 'womier/k87' , 'marvo/kg938']

for kb in BOARDS:
    subprocess.run(f"bin/qmk compile -kb {kb} -km all -j{os.cpu_count()}", shell=True)
