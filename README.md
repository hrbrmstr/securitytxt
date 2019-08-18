
[![Project Status: Active – The project has reached a stable, usable
state and is being actively
developed.](https://www.repostatus.org/badges/latest/active.svg)](https://www.repostatus.org/#active)
[![Signed
by](https://img.shields.io/badge/Keybase-Verified-brightgreen.svg)](https://keybase.io/hrbrmstr)
![Signed commit
%](https://img.shields.io/badge/Signed_Commits-100%25-lightgrey.svg)
[![Linux build
Status](https://travis-ci.org/hrbrmstr/securitytxt.svg?branch=master)](https://travis-ci.org/hrbrmstr/securitytxt)
[![Windows build
status](https://ci.appveyor.com/api/projects/status/github/hrbrmstr/securitytxt?svg=true)](https://ci.appveyor.com/project/hrbrmstr/securitytxt)
[![Coverage
Status](https://codecov.io/gh/hrbrmstr/securitytxt/branch/master/graph/badge.svg)](https://codecov.io/gh/hrbrmstr/securitytxt)
[![cran
checks](https://cranchecks.info/badges/worst/securitytxt)](https://cranchecks.info/pkgs/securitytxt)
[![CRAN
status](https://www.r-pkg.org/badges/version/securitytxt)](https://www.r-pkg.org/pkg/securitytxt)
![Minimal R
Version](https://img.shields.io/badge/R%3E%3D-3.2.0-blue.svg)
![License](https://img.shields.io/badge/License-MIT-blue.svg)

# securitytxt

Identify and Parse Web Security Policies Files

## Description

When security risks in web services are discovered by independent
security researchers who understand the severity of the risk, they often
lack the channels to properly disclose them. As a result, security
issues may be left unreported. The ‘security.txt’ ‘Web Security
Policies’ specification defines an ‘IETF’ draft standard
<https://tools.ietf.org/html/draft-foudil-securitytxt-00> to help
organizations define the process for security researchers to securely
disclose security vulnerabilities. Tools are provided to help identify
and parse ‘security.txt’ files to enable analysis of the usage and
adoption of these policies.

  - [IETF
    Draft](https://tools.ietf.org/html/draft-foudil-securitytxt-00)
  - [Information hub](https://securitytxt.org/)
  - [GitHub Organization](https://github.com/securitytxt)

## What’s Inside The Tin

The following functions are implemented:

  - `sectxt_info`: Retrieve a data frame of security.txt keys/values
  - `sectxt_url`: Determine security.txt URL for a given site/URL
  - `sectxt_validate`: Validate a security.txt Web Security Policies
    file
  - `sectxt`: Parse a security.txt Web Security Policies file & create a
    sectxt object

## Installation

``` r
install.packages("securitytxt", repos = "https://cinc.rud.is")
# or
remotes::install_git("https://git.rud.is/hrbrmstr/securitytxt.git")
# or
remotes::install_git("https://git.sr.ht/~hrbrmstr/securitytxt")
# or
remotes::install_gitlab("hrbrmstr/securitytxt")
# or
remotes::install_bitbucket("hrbrmstr/securitytxt")
# or
remotes::install_github("hrbrmstr/securitytxt")
```

NOTE: To use the ‘remotes’ install options you will need to have the
[{remotes} package](https://github.com/r-lib/remotes) installed.

## Usage

``` r
library(securitytxt)

# current verison
packageVersion("securitytxt")
## [1] '0.1.0'

# built-in example
x <- sectxt(readLines(system.file("extdata", "security.txt", package="securitytxt")))
sectxt_info(x)
```

<div class="kable-table">

| key        | value                             |
| :--------- | :-------------------------------- |
| contact    | <security@example.com>            |
| encryption | <https://example.com/pgp-key.txt> |

</div>

``` r

# "live" example
(xurl <- sectxt_url("https://securitytxt.org"))
## [1] "https://securitytxt.org/.well-known/security.txt"
x <- sectxt(url(xurl))
sectxt_info(x)
```

<div class="kable-table">

| key              | value                                        |
| :--------------- | :------------------------------------------- |
| contact          | <https://hackerone.com/ed>                   |
| encryption       | <https://keybase.pub/edoverflow/pgp_key.asc> |
| acknowledgements | <https://hackerone.com/ed/thanks>            |

</div>

``` r
sectxt_validate(x)
## [1] FALSE
x
## <Web Security Policies Object>
## # If you would like to report a security issue
## # you may report it to us on HackerOne.
## Contact: https://hackerone.com/ed
## Encryption: https://keybase.pub/edoverflow/pgp_key.asc
## Acknowledgements: https://hackerone.com/ed/thanks

# another "live" example
(xurl <- sectxt_url("https://rud.is/b"))
## [1] "https://rud.is/.well-known/security.txt"
x <- sectxt(url(xurl))
sectxt_info(x)
```

<div class="kable-table">

| key        | value                                                                                           |
| :--------- | :---------------------------------------------------------------------------------------------- |
| contact    | <bob@rud.is>                                                                                    |
| encryption | <https://keybase.io/hrbrmstr/pgp_keys.asc?fingerprint=e5388172b81c210906f5e5605879179645de9399> |
| disclosure | Full                                                                                            |

</div>

``` r
sectxt_validate(x)
## [1] TRUE
x
## <Web Security Policies Object>
## Contact: bob@rud.is
## Encryption: https://keybase.io/hrbrmstr/pgp_keys.asc?fingerprint=e5388172b81c210906f5e5605879179645de9399
## Disclosure: Full
```

## Code of Conduct

Please note that this project is released with a [Contributor Code of
Conduct](CONDUCT.md). By participating in this project you agree to
abide by its terms.
