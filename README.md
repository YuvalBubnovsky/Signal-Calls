# Operating-Systems-Exercise-2

### How to Run
firstly clone this repository to a convenient folder, after which you should open it using an IDE or navigate your CMD to that location and run the commands
``` make ``` and then ``` ./signal ``` which will execute our code, and finally ``` make clean ``` to remove the generated files.

### Example Run
![image](https://user-images.githubusercontent.com/73063105/161604179-90cefdec-2dd7-4980-9070-521bd6291176.png)

### How we accomplished raising 5 signals:
Firstly we use the ```signal()``` method to direct our signals to our own signal handler, rather than the default one. </br></br>
Now, the first signal we raise is a ```SIGCHLD``` signal using the ```fork()``` method, once the child dies the signal is raised and our handler raises the ```SIGUSR1``` signal using the ```raise()``` method, then the handler attempts the calculation of 2 divided by 0, which raises the ```SIGFPE``` signal, the handler than uses the ```abort()``` method to raise the ```SIGABRT``` signal, which finally uses the ```kill()``` method to raise the ```SIGCONT``` signal, and thus 5 signals were raised.
