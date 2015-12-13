#set the highlight
PS1='\[\e[31m\]\u@\h\[\e[35m\]:\[\e[94m\]\W\[\e[35m\]$(__git_ps1 " (%s)")\[\e[33m\]\$\[\e[36m\] '
# source ~/.bashrc


#add to path
export JAVA_HOME=/usr/lib/jdk8
export JRE_HOME=${JAVA_HOME}/jre
export CLASSPATH=.:${JAVA_HOME}/lib:${JRE_HOME}/lib
export PATH=${JAVA_HOME}/bin:$PATH
# source ~/.bashrc
# sudo update-alternatives --install /usr/bin/java java /usr/lib/jdk8/bin/java 300
# sudo update-alternatives --install /usr/bin/javac javac /usr/lib/jdk8/bin/javac 300
# sudo update-alternatives --config java
