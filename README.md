# C++ Q1: Compilation and Execution Instructions

## Compilation

To compile the provided C++ code, use the following command:

```bash
g++ a.cpp -std=c++17 -o samples/samples/a.exe
```

Explanation of the command:
- `g++`: The GNU C++ compiler.
- `a.cpp`: The source file containing the C++ code.
- `-std=c++17`: Specifies that the C++17 standard should be used.
- `-o samples/samples/a.exe`: Specifies the output file path and name for the compiled executable. The executable will be placed in the `samples/samples` directory with the name `a.exe`.

## Execution

Once the code is compiled, it must be executed from the **same directory** as where the sample files are located, and where the `a.exe` file was generated.

To run the executable, use the following command:

```bash
./a.exe [filename]
```

- Replace `[filename]` with the actual name of the input file.
  
Example:
```bash
./a.exe sample_1
```

### Running All Files

To execute the code on **all sample files** at once, use the following command:

```bash
./a.exe all
```

This will process all files in the `samples` directory that follow the `sample_N` naming pattern and generate the corresponding solution files.

## Output

When you run the executable with an appropriate input file:
1. The program will print the output directly to the console.
2. Additionally, a solution file will be generated, named `sol_N` (where `N` matches the number in the input file name `sample_N`).

For example:
- If the input file is `sample_1`, the program will create an output file `sol_1`.

Make sure the input files follow the format `sample_N` (e.g., `sample_1`, `sample_2`, etc.) for the solution file to be correctly named.

## Precomputed Output Files

Precomputed output files for sample inputs are already present in the `samples` folder. These files are named `sol_N`, where `N` corresponds to the input file name `sample_N`. If you run the program with the same input files, the output will be overwritten.