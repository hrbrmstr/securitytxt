## Test environments
* local OS X install, R 3.4.2
* ubuntu 14.04 (on travis-ci), R oldrel, release & devel
* ubuntu 16.04.3 (local), R 3.4.1
* r-hub Windows
* win-builder (devel and release)

## R CMD check results

0 errors | 0 warnings | 1 note

* This is a new release.

## Reverse dependencies

This is a new release, so there are no reverse dependencies.

---

* I've used the new ORCID id in
  Authors@R (not sure if I need
  to note that but it's "new" so
  figured it wldn't hurt to 
  mention it).
* There is extra copyright info
  for the included C++ lib used
  both in inst/COPYRIGHTS &
  in the C++ source files.
* Some examples that require
  internet connectivity are 
  marked 'dontrun' b/c they 
  are for illustration only.
* Tests are included  and run
  weekly on Travis-CI
* Tests are manuall run on AppVeyor
  as well for all builds.
* Code coverage is also provided.