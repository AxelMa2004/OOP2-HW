all: main

CXX = clang++
override CXXFLAGS += -g -Wall -Werror --std=c++17 -Iinclude

ifeq ($(OS),Windows_NT)
# Plain Windows has no find, sed or rm: use make's own wildcard (three folder levels) and cmd's del.
# The targets stay `main` / `main-debug`; only the file name gets .exe.
# wildcard splits a name with spaces (`x copy.cpp`) into words: `names` glues the words back until
# the name ends in the extension and exists (`?` matches the space), each space escaped as `\ `.
# cmd does not understand `\ `, so the compiler gets every source in quotes (QSRCS; `?` cannot
# occur in a Windows file name, so it stands for the space while the list is split).
EXE = .exe
nothing :=
space := $(nothing) $(nothing)
glue = $(eval _w := $(if $(_w),$(_w)\$(space)$(2),$(2)))$(if $(and $(filter %$(1),$(_w)),$(wildcard $(subst \$(space),?,$(_w)))),$(_w)$(eval _w :=))
names = $(eval _w :=)$(strip $(foreach w,$(2),$(call glue,$(1),$(w))))
SRCS := $(filter-out .cppbox-cache/%,$(call names,.cpp,$(wildcard *.cpp */*.cpp */*/*.cpp)))
HEADERS := $(filter-out .cppbox-cache/%,$(call names,.h,$(wildcard *.h */*.h */*/*.h)))
QSRCS = $(foreach s,$(subst \$(space),?,$(SRCS)),"$(subst ?,$(space),$(s))")
RM = cmd /C del /Q /F
CLEAN_DIRS =
else
CLEAN_DIRS = main.dSYM main-debug.dSYM
SRCS = $(shell find . -name '.cppbox-cache' -type d -prune -o -type f -name '*.cpp' -print | sed -e 's/ /\\ /g')
HEADERS = $(shell find . -name '.cppbox-cache' -type d -prune -o -type f -name '*.h' -print)
QSRCS = $(SRCS)
endif

main: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(QSRCS) -o "$@$(EXE)"

main-debug: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -O0 $(QSRCS) -o "$@$(EXE)"

clean:
	-$(RM) main main-debug main.exe main-debug.exe main.pdb main-debug.pdb
	-$(if $(CLEAN_DIRS),rm -rf $(CLEAN_DIRS))