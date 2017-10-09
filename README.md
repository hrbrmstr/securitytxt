
[![Build Status](https://travis-ci.org/hrbrmstr/securitytxt.svg?branch=master)](https://travis-ci.org/hrbrmstr/securitytxt) [![Build status](https://ci.appveyor.com/api/projects/status/o654jge4mce4a7lg?svg=true)](https://ci.appveyor.com/project/hrbrmstr/securitytxt) ![Coverage Status](http://img.shields.io/codecov/c/github/hrbrmstr/securitytxt/master.svg)

securitytxt
===========

Identify and Parse Web Security Policies Files

Description
-----------

When security risks in web services are discovered by independent security researchers who understand the severity of the risk, they often lack the channels to properly disclose them. As a result, security issues may be left unreported. The 'security.txt' 'Web Security Policies' specification defines a 'IETF' standard to help organizations define the process for security researchers to securely disclose security vulnerabilities.

Tools are provided to identify and parse 'security.txt' files, enabling analysis of the usage of these policies.

-   [IETF Draft](https://tools.ietf.org/html/draft-foudil-securitytxt-00)
-   [Information hub](https://securitytxt.org/)
-   [GitHub Organization](https://github.com/securitytxt)

What's Inside The Tin
---------------------

The following functions are implemented:

-   `sectxt`: Parse a 'security.txt' Web Security Policies file & create a 'sectxt' object
-   `sectxt_info`: Retrieve a data frame of `security.txt` keys/values
-   `sectxt_validate`: Validate a 'security.txt' Web Security Policies file
-   `sectxt_url`: Determine `security.txt` URL for a given site/URL

Installation
------------

``` r
devtools::install_github("hrbrmstr/securitytxt")
```

Usage
-----

``` r
library(securitytxt)

# current verison
packageVersion("securitytxt")
```

    ## [1] '0.1.0'

``` r
# built-in example
x <- sectxt(readLines(system.file("extdata", "security.txt", package="securitytxt")))
sectxt_info(x)
```

    ##          key                           value
    ## 1    contact            security@example.com
    ## 2 encryption https://example.com/pgp-key.txt

``` r
# "live" example
(xurl <- sectxt_url("https://securitytxt.org"))
```

    ## [1] "https://securitytxt.org/.well-known/security.txt"

``` r
x <- sectxt(url(xurl))
sectxt_info(x)
```

    ##       key                          value
    ## 1 contact https://twitter.com/EdOverflow

``` r
sectxt_validate(x)
```

    ## [1] TRUE

``` r
x
```

    ## <Web Security Policies Object>
    ## # Our security address
    ## Contact: https://twitter.com/EdOverflow

``` r
# another "live" example
(xurl <- sectxt_url("https://rud.is/b"))
```

    ## [1] "https://rud.is/.well-known/security.txt"

``` r
x <- sectxt(url(xurl))
sectxt_info(x)
```

    ##          key                                                                                         value
    ## 1    contact                                                                                    bob@rud.is
    ## 2 encryption https://keybase.io/hrbrmstr/pgp_keys.asc?fingerprint=e5388172b81c210906f5e5605879179645de9399
    ## 3 disclosure                                                                                          Full

``` r
sectxt_validate(x)
```

    ## [1] TRUE

``` r
x
```

    ## <Web Security Policies Object>
    ## Contact: bob@rud.is
    ## Encryption: https://keybase.io/hrbrmstr/pgp_keys.asc?fingerprint=e5388172b81c210906f5e5605879179645de9399
    ## Disclosure: Full

Code of Conduct
---------------

Please note that this project is released with a [Contributor Code of Conduct](CONDUCT.md). By participating in this project you agree to abide by its terms.
