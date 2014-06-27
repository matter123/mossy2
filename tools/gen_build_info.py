# Copyright 2014 Matthew Fosdick

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at

         # http://www.apache.org/licenses/LICENSE-2.0

# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import os
import os.path as path
import time
import getpass
import subprocess


def combine(path1, path2):
    return path.normpath(path.join(path1, path2))


def gen(srcfolder):

    build_info = combine(srcfolder, "./src/stdlib/include/build_info.h")
    bi = open(build_info, "w")
    bi.write(
        "/*temp file full of build info, " +
        "generated by tools/gen_build_info.py.")
    bi.write(
        "\nContents in this file are not " +
        "copyrighted material unless obtained\n")
    bi.write("from a copyrighted source*/\n")
    bi.write("#pragma once\n")
    bi.write("#define BUILD_UNIX_TIME ")
    bi.write(str(int(time.time())) + "L\n")
    bi.write("#define BUILD_USERNAME \"")
    bi.write(str(getpass.getuser()) + "\"\n")
    bi.write("#define BUILD_GIT_BRANCH \"")
    old_cwd = os.getcwd()
    os.chdir(srcfolder)
    out = subprocess.Popen(
        ["git", "status"], stdout=subprocess.PIPE).communicate()[0]
    os.chdir(old_cwd)
    bi.write((str(out).splitlines()[0].split(" ")[2] + "\"\n"))
    bi.close()


def delete(srcfolder):
    build_info = combine(
        path.dirname(srcfolder), "./src/stdlib/include/build_info.h")
    os.remove(build_info)
