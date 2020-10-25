<?php

echo sprintf("pid is %s, ppid is %s\nuid is %s, gid is %s\neuid is %s, egid is %s\n",
 posix_getpid(), posix_getppid(),
 posix_getuid(), posix_getgid(),
 posix_geteuid(), posix_getegid()
);