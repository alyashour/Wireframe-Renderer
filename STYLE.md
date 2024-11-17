# Style Notes
<u>Write files in PascalCase</u>  
E.g., `MyFile.cpp` or `HeaderFile.hpp`  
This is not standard I'm just deciding this for this repo.

<u>Include std lib headers first, then 3rd party libs, then custom headers last.</u>  
```c++
// std includes
#include <iostream>
#include <string>
#include <vector>

// 3rd party libs
#include <Eigen>

// custom
#include "MyFile.hpp"
#include "MyOtherFile.hpp"
```