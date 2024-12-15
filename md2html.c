#include <sys/queue.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <lowdown.h>
#include <err.h>

/* from lowdown(3) */
int main(void) 
{
	struct lowdown_opts opts;
	char *buf;
	size_t bufsz;

	memset(&opts, '\0', sizeof(struct lowdown_opts));
	
	opts.type = LOWDOWN_HTML;

	opts.feat = LOWDOWN_AUTOLINK | LOWDOWN_FENCED | LOWDOWN_ATTRS | LOWDOWN_MATH |
		LOWDOWN_METADATA | LOWDOWN_STRIKE | LOWDOWN_SUPER | LOWDOWN_TABLES |
		LOWDOWN_TASKLIST;
	opts.oflags = LOWDOWN_SMARTY | LOWDOWN_HTML_OWASP | LOWDOWN_HTML_NUM_ENT | 
		LOWDOWN_HTML_HEAD_IDS;

	opts.maxdepth = 128;

	if (!lowdown_file(&opts, stdin, &buf, &bufsz, NULL))
		errx(1, "lowdown_file");
	fwrite(buf, 1, bufsz, stdout);
	free(buf);
}
