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
