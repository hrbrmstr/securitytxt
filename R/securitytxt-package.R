#' Identify and Parse Web Security Policies Files
#'
#' When security risks in web services are discovered by independent
#' security researchers who understand the severity of the risk, they
#' often lack the channels to properly disclose them. As a result,
#' security issues may be left unreported. The 'security.txt' 'Web Security Policies'
#' specification defines a 'IETF' standard to help organizations define the process
#' for security researchers to securely disclose security vulnerabilities. Tools are
#' provided to help identify and parse 'security.txt' files to enable analysis of
#' the usage of these policies.
#'
#' @md
#' @name securitytxt
#' @references [IETF Draft](https://tools.ietf.org/html/draft-foudil-securitytxt-00); [Information hub](https://securitytxt.org/)
#'     [GitHub Organization](https://github.com/securitytxt)
#' @docType package
#' @author Bob Rudis (bob@@rud.is)
#' @useDynLib securitytxt
#' @importFrom Rcpp sourceCpp
NULL