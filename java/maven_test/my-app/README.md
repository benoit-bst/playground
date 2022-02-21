## package

With this configuration, we can package like this

```sh
mvn clean dependency:copy-dependencies package
```

run

```sh
java -jar target/my-app-1.0-SNAPSHOT.jar
```
