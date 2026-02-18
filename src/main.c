#include "cv.h"

static void	populate_competencies(t_cv *cv)
{
	cv->competencies = competencies_init();

	// Languages
	skill_add_back(&cv->competencies->languages, skill_new("C"));
	skill_add_back(&cv->competencies->languages, skill_new("Bash"));

	// Tools
	skill_add_back(&cv->competencies->tools, skill_new("Linux"));
	skill_add_back(&cv->competencies->tools, skill_new("Docker"));
	skill_add_back(&cv->competencies->tools, skill_new("VirtualBox"));
	skill_add_back(&cv->competencies->tools, skill_new("Git/GitHub"));
	skill_add_back(&cv->competencies->tools, skill_new("VSCode"));
	skill_add_back(&cv->competencies->tools, skill_new("Vim"));
	skill_add_back(&cv->competencies->tools, skill_new("n8n"));

	// Technical skills
	skill_add_back(&cv->competencies->technical_skills, skill_new("C / Low-level: Parsing / Memory management"));
	skill_add_back(&cv->competencies->technical_skills, skill_new("UNIX processes / Pipes and redirections / Debugging"));
	skill_add_back(&cv->competencies->technical_skills, skill_new("Bash scripting, task automation, API usage (CLI / curl)"));
	skill_add_back(&cv->competencies->technical_skills, skill_new("Teamwork, project management, analysis and problem-solving"));

	// Spoken languages
	skill_add_back(&cv->competencies->spoken_languages, skill_new("French (native)"));
	skill_add_back(&cv->competencies->spoken_languages, skill_new("Spanish (fluent)"));
	skill_add_back(&cv->competencies->spoken_languages, skill_new("English (fluent)"));
}

static void	populate_projects(t_cv *cv)
{
	t_project	*project;

	// MiniShell
	project = project_new(
		"MiniShell (C)",
		"42 Barcelona",
		"Implementation of a simplified shell: parsing, pipes, redirections, "
		"command execution and memory management."
	);
	skill_add_back(&project->technologies, skill_new("C"));
	skill_add_back(&project->technologies, skill_new("System calls"));
	skill_add_back(&project->technologies, skill_new("Makefile"));
	add_project(cv, project);

	// Philosophers
	project = project_new(
		"Philosophers (C)",
		"42 Barcelona",
		"Concurrent programming with mutex and deadlock prevention."
	);
	skill_add_back(&project->technologies, skill_new("C"));
	skill_add_back(&project->technologies, skill_new("Threads / Mutex"));
	add_project(cv, project);

	// Pipex
	project = project_new(
		"Pipex (C)",
		"42 Barcelona",
		"Recreation of UNIX pipelines."
	);
	skill_add_back(&project->technologies, skill_new("C"));
	skill_add_back(&project->technologies, skill_new("UNIX pipes"));
	skill_add_back(&project->technologies, skill_new("fork / exec"));
	add_project(cv, project);

	// Push_swap
	project = project_new(
		"Push_swap (C)",
		"42 Barcelona",
		"Algorithmic optimization: sorting with a minimal set of stack operations."
	);
	skill_add_back(&project->technologies, skill_new("C"));
	skill_add_back(&project->technologies, skill_new("Algorithms"));
	skill_add_back(&project->technologies, skill_new("Stacks"));
	add_project(cv, project);

	// So_long
	project = project_new(
		"So_long (C)",
		"42 Barcelona",
		"Game logic and basic 2D graphics."
	);
	skill_add_back(&project->technologies, skill_new("C"));
	skill_add_back(&project->technologies, skill_new("MiniLibX"));
	add_project(cv, project);

	// Libft / GNL
	project = project_new(
		"Libft / Get_next_line (C)",
		"42 Barcelona",
		"Custom C library reimplementing standard functions, and line-by-line "
		"file reading with buffer management."
	);
	skill_add_back(&project->technologies, skill_new("C"));
	skill_add_back(&project->technologies, skill_new("Memory management"));
	skill_add_back(&project->technologies, skill_new("Linked lists"));
	add_project(cv, project);

	// Bash & AI automation
	project = project_new(
		"Bash & AI Automation",
		"Personal projects",
		"Automation with Bash and AI tools (n8n). Simple API scraping bot. "
		"Linux workflow scripts."
	);
	skill_add_back(&project->technologies, skill_new("Bash"));
	skill_add_back(&project->technologies, skill_new("n8n"));
	skill_add_back(&project->technologies, skill_new("REST APIs / curl"));
	add_project(cv, project);

	// Electronics
	project = project_new(
		"Electronics & Hardware",
		"Personal projects",
		"Soldering, PCB component replacement, motherboard repair, portable console "
		"modding, audio equipment repair (microphones), audio cable fabrication, "
		"low-voltage electrical work."
	);
	skill_add_back(&project->technologies, skill_new("Soldering"));
	skill_add_back(&project->technologies, skill_new("PCB repair"));
	skill_add_back(&project->technologies, skill_new("Electrical wiring"));
	add_project(cv, project);
}

static void	populate_education(t_cv *cv)
{
	t_education	*edu;

	// 42 Barcelona
	edu = education_new(
		"Computer Science Training",
		"42 School",
		"Barcelona, Spain",
		"March 2025",
		"Ongoing",
		"Intensive low-level C development: memory, concurrency, UNIX processes "
		"and algorithms. Project-based, peer-to-peer methodology."
	);
	add_education(cv, edu);

	// Electrician
	edu = education_new(
		"Professional Electrician Certificate",
		"L'École Des Pros",
		"Paris, France",
		"December 2021",
		"June 2022",
		"Electrical installation, maintenance and wiring"
	);
	add_education(cv, edu);

	// Audio engineering
	edu = education_new(
		"Professional Certificate in Audio Engineering and Music",
		"Recording Arts Canada",
		"Montreal, Canada",
		"January 2018",
		"January 2019",
		"Recording, mixing, mastering and professional software"
	);
	add_education(cv, edu);

	// Biology
	edu = education_new(
		"Bachelor's degree in Biology",
		"University of Montreal",
		"Montreal, Canada",
		"September 2014",
		"December 2017",
		"Scientific analysis, laboratory skills and animal biology"
	);
	add_education(cv, edu);
}

static void	populate_experience(t_cv *cv)
{
	t_experience	*exp;

	// Studio 22 Barcelona
	exp = experience_new(
		"Sound Engineer",
		"Studio 22",
		"Barcelona, Spain",
		"March 2023",
		"March 2025"
	);
	skill_add_back(&exp->responsibilities, skill_new("Professional audio recording and mixing"));
	skill_add_back(&exp->responsibilities, skill_new("Project management and session planning"));
	skill_add_back(&exp->responsibilities, skill_new("Client relations and technical communication"));
	skill_add_back(&exp->responsibilities, skill_new("Teamwork and resource coordination"));
	add_experience(cv, exp);

	// Studio Niel Paris
	exp = experience_new(
		"Sound Engineer",
		"Studio Niel",
		"Paris, France",
		"June 2019",
		"June 2022"
	);
	skill_add_back(&exp->responsibilities, skill_new("Audio recording and mixing"));
	skill_add_back(&exp->responsibilities, skill_new("Project management"));
	skill_add_back(&exp->responsibilities, skill_new("Client relations"));
	skill_add_back(&exp->responsibilities, skill_new("Production team coordination"));
	add_experience(cv, exp);

	// JP Sausset
	exp = experience_new(
		"Electrician",
		"JP Sausset Electricite",
		"France",
		"June 2022",
		"September 2022"
	);
	skill_add_back(&exp->responsibilities, skill_new("Electrical installation and wiring"));
	skill_add_back(&exp->responsibilities, skill_new("On-site maintenance and troubleshooting"));
	add_experience(cv, exp);
}

int	main(void)
{
	t_cv	*cv;

	cv = cv_init();
	if (!cv)
		return (1);

	// Personal information
	cv->name = strdup("Timothee Pablo Mege");
	cv->title = strdup("Junior Software Developer – C / Systems / UNIX");
	cv->location = strdup("Barcelona, Spain");
	cv->email = strdup("t.p.mege@gmail.com");
	cv->phone = strdup("+34613444715");
	cv->github = strdup("github.com/tmege");
	cv->profile = strdup(
		"Computer science student at 42 Barcelona,\n"
		"specializing in C development and UNIX systems.\n"
		"\n"
		"Hands-on experience in parsing, memory management,\n"
		"concurrency and automation.\n"
		"\n"
		"Autonomous and problem-solving oriented profile,\n"
		"seeking a junior backend / systems / software developer position\n"
		"to continue growing technically."
	);

	// Populate sections
	populate_competencies(cv);
	populate_projects(cv);
	populate_education(cv);
	populate_experience(cv);

	// Interactive menu
	run_menu(cv);

	// Free memory
	free_cv(cv);

	return (0);
}
