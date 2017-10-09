#include <Rcpp.h>
using namespace Rcpp;

#include "url.h"
#include "security.h"

//' Parse security.txt
//'
//' @noRd
//'
// [[Rcpp::export]]
SEXP sectxt_parse(std::string content) {
  Rcpp::XPtr<SecTxt::SecurityText> ptr(new SecTxt::SecurityText(content));
  return(ptr);
}

// [[Rcpp::export]]
std::string sectxt_raw(SEXP x) {

  Rcpp::XPtr<SecTxt::SecurityText> ptr(x);
  return(ptr->rawFile());

}

// [[Rcpp::export]]
std::vector< std::string > sectxt_keys(SEXP x) {

  Rcpp::XPtr<SecTxt::SecurityText> ptr(x);
  return(ptr->sectxtKeys());

}


//' Retrieve a data frame of security.txt keys/values
//'
//' @md
//' @param x a parsed `security.txt` created with [sec_parse()]
//' @return data frame
//' @export
// [[Rcpp::export]]
DataFrame sectxt_info(SEXP x) {

  Rcpp::XPtr<SecTxt::SecurityText> ptr(x);

  return(DataFrame::create(
      _["key"] = ptr->sectxtKeys(),
      _["value"] = ptr->sectxtVals()));

}

//' Determine security.txt URL for a given site/URL
//'
//' Provide any URL for a resource and retrieve the URL for
//' the `security.txt` file. Strips off extraneous URL
//' components and appends `.well-known/security.txt`.
//'
//' @md
//' @param url URL
//' @return character vector
//' @export
//' @examples
//' sectxt_url("https://securitytxt.org/this/that/the/other.html")
// [[Rcpp::export]]
std::string sectxt_url(std::string url) {
  return(SecTxt::SecurityText::securityUrl(url));
}
