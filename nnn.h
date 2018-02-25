/* See LICENSE file for copyright and license details. */
#define CONTROL(c) ((c) ^ 0x40)

/* Supported actions */
enum action {
	SEL_BACK = 1,
	SEL_GOIN,
	SEL_NEXT,
	SEL_PREV,
	SEL_PGDN,
	SEL_PGUP,
	SEL_HOME,
	SEL_END,
	SEL_CD,
	SEL_CDHOME,
	SEL_CDBEGIN,
	SEL_CDLAST,
	SEL_CDBM,
	SEL_PIN,
	SEL_VISIT,
	SEL_FLTR,
	SEL_MFLTR,
	SEL_SEARCH,
	SEL_TOGGLEDOT,
	SEL_DETAIL,
	SEL_STATS,
	SEL_MEDIA,
	SEL_FMEDIA,
	SEL_DFB,
	SEL_LIST,
	SEL_EXTRACT,
	SEL_FSIZE,
	SEL_BSIZE,
	SEL_MTIME,
	SEL_REDRAW,
	SEL_COPY,
	SEL_COPYMUL,
	SEL_QUOTE,
	SEL_OPEN,
	SEL_NEW,
	SEL_RENAME,
	SEL_HELP,
	SEL_RUN,
	SEL_RUNARG,
	SEL_CDQUIT,
	SEL_QUIT,
};

/* Associate a pressed key to an action */
struct key {
	int sym;         /* Key pressed */
	enum action act; /* Action */
	char *run;       /* Program to run or program option */
	char *env;       /* Environment variable to run */
};

/* Extension pattern and mime combination */
struct assoc {
	char *regex; /* Regex to match on filename */
	char *mime;  /* File type */
};

static struct assoc assocs[] = {
	{ "\\.(c|cpp|h|log|md|py|sh|txt)$", "text" },
};

static struct key bindings[] = {
	/* Back */
	{ KEY_BACKSPACE,  SEL_BACK,      "",     "" },
	{ KEY_LEFT,       SEL_BACK,      "",     "" },
	{ 'h',            SEL_BACK,      "",     "" },
	{ CONTROL('H'),   SEL_BACK,      "",     "" },
	/* Inside */
	{ KEY_ENTER,      SEL_GOIN,      "",     "" },
	{ '\r',           SEL_GOIN,      "",     "" },
	{ KEY_RIGHT,      SEL_GOIN,      "",     "" },
	{ 'l',            SEL_GOIN,      "",     "" },
	/* Next */
	{ 'j',            SEL_NEXT,      "",     "" },
	{ KEY_DOWN,       SEL_NEXT,      "",     "" },
	{ CONTROL('N'),   SEL_NEXT,      "",     "" },
	/* Previous */
	{ 'k',            SEL_PREV,      "",     "" },
	{ KEY_UP,         SEL_PREV,      "",     "" },
	{ CONTROL('P'),   SEL_PREV,      "",     "" },
	/* Page down */
	{ KEY_NPAGE,      SEL_PGDN,      "",     "" },
	{ CONTROL('D'),   SEL_PGDN,      "",     "" },
	/* Page up */
	{ KEY_PPAGE,      SEL_PGUP,      "",     "" },
	{ CONTROL('U'),   SEL_PGUP,      "",     "" },
	/* First entry */
	{ KEY_HOME,       SEL_HOME,      "",     "" },
	{ 'g',            SEL_HOME,      "",     "" },
	{ CONTROL('A'),   SEL_HOME,      "",     "" },
	{ '^',            SEL_HOME,      "",     "" },
	/* Last entry */
	{ KEY_END,        SEL_END,       "",     "" },
	{ 'G',            SEL_END,       "",     "" },
	{ CONTROL('E'),   SEL_END,       "",     "" },
	{ '$',            SEL_END,       "",     "" },
	/* Change dir */
	{ 'c',            SEL_CD,        "",     "" },
	/* HOME */
	{ '~',            SEL_CDHOME,    "",     "" },
	/* Initial directory */
	{ '&',            SEL_CDBEGIN,   "",     "" },
	/* Last visited dir */
	{ '-',            SEL_CDLAST,    "",     "" },
	/* Change dir using bookmark */
	{ CONTROL('B'),   SEL_CDBM,      "",     "" },
	/* Mark a path to visit later */
	{ 'b',            SEL_PIN,       "",     "" },
	/* Visit marked directory */
	{ CONTROL('V'),   SEL_VISIT,     "",     "" },
	/* Filter */
	{ '/',            SEL_FLTR,      "",     "" },
	/* Toggle filter mode */
	{ KEY_IC,         SEL_MFLTR,     "",     "" },
	/* Desktop search */
	{ CONTROL('_'),   SEL_SEARCH,    "",     "" },
	/* Toggle hide .dot files */
	{ '.',            SEL_TOGGLEDOT, "",     "" },
	/* Detailed listing */
	{ 'd',            SEL_DETAIL,    "",     "" },
	/* File details */
	{ 'D',            SEL_STATS,     "",     "" },
	/* Show media info short, run is hacked */
	{ 'm',            SEL_MEDIA,     NULL,   "" },
	/* Show media info full, run is hacked */
	{ 'M',            SEL_FMEDIA,    "-f",   "" },
	/* Open dir in desktop file manager */
	{ 'o',            SEL_DFB,       "",     "" },
	/* List archive */
	{ 'F',            SEL_LIST,      "-l", "" },
	/* Extract archive */
	{ CONTROL('F'),   SEL_EXTRACT,   "-x", "" },
	/* Toggle sort by size */
	{ 's',            SEL_FSIZE,     "",     "" },
	/* Sort by total block count including dir contents */
	{ 'S',            SEL_BSIZE,     "",     "" },
	{ CONTROL('J'),   SEL_BSIZE,     "",     "" },
	/* Toggle sort by time */
	{ 't',            SEL_MTIME,     "",     "" },
	/* Redraw window */
	{ CONTROL('L'),   SEL_REDRAW,    "",     "" },
	{ KEY_F(5),       SEL_REDRAW,    "",     "" }, /* Undocumented */
	/* Copy currently selected file path */
	{ 'y',            SEL_COPY,      "",     "" },
	/* Toggle copy multiple file paths */
	{ CONTROL('Y'),   SEL_COPYMUL,   "",     "" },
	/* Toggle quote on while copy */
	{ CONTROL('T'),   SEL_QUOTE,     "",     "" },
	/* Open in a custom application */
	{ CONTROL('O'),   SEL_OPEN,      "",     "" },
	/* Create a new file */
	{ 'n',            SEL_NEW,       "",     "" },
	/* Show rename prompt */
	{ CONTROL('R'),   SEL_RENAME,    "",     "" },
	{ KEY_F(2),       SEL_RENAME,    "",     "" }, /* Undocumented */
	/* Show help */
	{ '?',            SEL_HELP,      "",     "" },
	/* Run command */
	{ '!',            SEL_RUN,       "sh",   "SHELL" },
	/* Run command with argument */
	{ 'e',            SEL_RUNARG,    "vi",   "EDITOR" },
	{ 'p',            SEL_RUNARG,    "less", "PAGER" },
	/* Change dir on quit */
	{ 'Q',            SEL_CDQUIT,    "",     "" },
	/* Quit */
	{ 'q',            SEL_QUIT,      "",     "" },
	{ CONTROL('X'),   SEL_QUIT,      "",     "" },
};
