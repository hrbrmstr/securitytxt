#' Parse a `security.txt` Web Security Policies file & create a `sectxt` object
#'
#' This function takes in a single element character vector and parses it into
#' a `sectxt` object.
#'
#' @md
#' @param x either an atomic character vector containing a complete `security.txt` file
#'        _or_ a length >1 character vector that will be concatenated into a single string _or_
#'        a `connection` object that will be passed to [readLines()], the result of which
#'        will be concatenated into a single string and parsed and the connection will be closed.
#' @references [IETF Draft](https://tools.ietf.org/html/draft-foudil-securitytxt-00); [Information hub](https://securitytxt.org/)
#'     [GitHub Organization](https://github.com/securitytxt)
#' @export
#' @examples
#' sectxt(readLines(system.file("extdata", "security.txt", package="securitytxt")))
#' \dontrun{
#' sectxt(url(sectxt_url("https://securitytxt.org")))
#' }
sectxt <- function(x) {

  if (inherits(x, "connection")) {
    y <- suppressWarnings(try(readLines(x, warn = FALSE), silent=TRUE))
    if (inherits(y, "try-error")) {
      warning("security.txt not found")
      return(NULL)
    }
    close(x)
    x <- y
  }
  if (is.character(x)) if (length(x) > 1) x <- paste0(x, collapse="\n")

  sec_txt <- sectxt_parse(x)
  class(sec_txt) <- c("sectxt")

  sec_txt

}

#' Custom printer for `sectxt`` objects
#'
#' @md
#' @noRd
#' @keywords internal
#' @param x object to print
#' @param ... unused
#' @export
print.sectxt <- function(x, ...) {
  cat("<Web Security Policies Object>\n", sep="")
  cat(sectxt_raw(x))
  invisible(x)
}