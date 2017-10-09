securitytxt_ietf_fields <- c("contact", "encryption", "acknowledgement", "disclosure")

#' Validate a `security.txt` Web Security Policies file
#'
#' @md
#' @param x an object created with [sectxt()]
#' @return logical; `TRUE` if all fields match current IETF standard, `FALSE` if not
#' @export
sectxt_validate <- function(x) {
  tmp_keys <- sectxt_keys(x)
  key_test <- tmp_keys %in% securitytxt_ietf_fields
  if (any(key_test == FALSE)) {
    message(sprintf("The following keys were found that are not in the current IETF standard: %s",
                    paste0(tmp_keys[which(key_test == FALSE)], sep=", ")))
    FALSE
  } else {
    TRUE
  }
}