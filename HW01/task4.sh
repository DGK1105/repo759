#!/bin/bash
#SBATCH --job-name=FirstSlurm     # Job name
#SBATCH --output=FirstSlurm.out    # Output file
#SBATCH --error=FirstSlurm.err     # Error file
#SBATCH --ntasks=1                 # Run on a single task (1 node)
#SBATCH --cpus-per-task=2          # Request 2 CPU cores

# Command to print the hostname of the compute node
hostname

