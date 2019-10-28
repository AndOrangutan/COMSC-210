clock_t startTime = clock(); // start the virtual stop watch...
//stuff
clock_t endTime = clock(); // ...stop the virtual stop watch

double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;

fin.close();

std::cout << elapsedSeconds << "(expected " << elapsedSecondsFirst << ") for n=" << n << std::endl;
double elapsedSecondsFirst = elapsedSecondsFirst * 2;