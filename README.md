# javaperfstat: Sample Java wrapper for libperfstat API

To compile this code:
```
cc -q64  -G -I/usr/java8_64/include/ javaperfstat.c -o libjavaperfstat.so -lperfstat
```

To Mavenize this: 

```
mvn install:install-file -Dfile=/home/joe/libjavaperfstat.so -DgroupId=com.ibm.aix -DartifactId=libjavaperfstat -Dversion=1.0.0 -Dpackaging=so 
```

To Use this java project, add dependencies as follows,

```xml
    <dependency>
      <groupId>com.ibm.aix</groupId>
      <artifactId>libjavaperfstat</artifactId>
      <version>1.0.0</version>
      <type>so</type>
    </dependency>
```

###Notice

© Copyright IBM Corporation 2016.

###License

```
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
```
