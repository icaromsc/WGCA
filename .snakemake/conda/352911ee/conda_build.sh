if [ -z ${CONDA_BUILD+x} ]; then
	source /opt/conda/conda-bld/abricate_1555992207693/work/build_env_setup.sh
fi
#!/bin/bash

set -e
./bin/abricate --setupdb

mkdir -p $PREFIX/bin
cp -r * $PREFIX
