#include "cv.h"

/* ========== PRINT HELPERS ========== */

static void	print_skill_list(t_skill *skills)
{
	while (skills)
	{
		printf("  • %s\n", skills->name);
		skills = skills->next;
	}
}

static void	print_separator(void)
{
	printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
}

static int	utf8_len(const char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		if ((*str & 0xC0) != 0x80)
			len++;
		str++;
	}
	return (len);
}

static void	print_centered(const char *str, int width)
{
	int	len;
	int	pad_left;
	int	pad_right;
	int	i;

	len = utf8_len(str);
	pad_left = (width - len) / 2;
	pad_right = width - len - pad_left;
	printf("██");
	i = -1;
	while (++i < pad_left)
		printf(" ");
	printf("%s", str);
	i = -1;
	while (++i < pad_right)
		printf(" ");
	printf("██\n");
}

/* ========== PRINT FUNCTIONS ========== */

void	print_competencies(t_competencies *comp)
{
	if (!comp)
		return ;
	printf("╔══════════════════════════════════════════════════════════════════╗\n");
	printf("║                    TECHNICAL SKILLS                              ║\n");
	printf("╚══════════════════════════════════════════════════════════════════╝\n\n");

	if (comp->languages)
	{
		printf("Languages:\n");
		print_skill_list(comp->languages);
		printf("\n");
	}
	if (comp->tools)
	{
		printf("Tools:\n");
		print_skill_list(comp->tools);
		printf("\n");
	}
	if (comp->systems)
	{
		printf("Systems:\n");
		print_skill_list(comp->systems);
		printf("\n");
	}
	if (comp->technical_skills)
	{
		printf("Technical skills:\n");
		print_skill_list(comp->technical_skills);
		printf("\n");
	}
	if (comp->spoken_languages)
	{
		printf("Spoken languages:\n");
		print_skill_list(comp->spoken_languages);
	}
}

void	print_projects(t_project *projects)
{
	printf("╔══════════════════════════════════════════════════════════════════╗\n");
	printf("║           PROJECTS & DEVELOPMENT EXPERIENCE                      ║\n");
	printf("╚══════════════════════════════════════════════════════════════════╝\n\n");

	while (projects)
	{
		printf("▸ %s\n", projects->title);
		printf("  %s\n\n", projects->location);
		printf("  %s\n", projects->description);

		if (projects->technologies)
		{
			printf("\n  Technologies used:\n");
			print_skill_list(projects->technologies);
		}

		if (projects->next)
			printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
		projects = projects->next;
	}
}

void	print_education(t_education *education)
{
	printf("╔══════════════════════════════════════════════════════════════════╗\n");
	printf("║                 EDUCATION & QUALIFICATIONS                       ║\n");
	printf("╚══════════════════════════════════════════════════════════════════╝\n\n");

	while (education)
	{
		printf("▸ %s\n", education->title);
		printf("  %s, %s\n", education->institution, education->location);
		printf("  %s - %s\n", education->start_date, education->end_date);
		if (education->description && strlen(education->description) > 0)
			printf("  %s\n", education->description);

		if (education->next)
			printf("\n");
		education = education->next;
	}
}

void	print_experience(t_experience *exp)
{
	printf("╔══════════════════════════════════════════════════════════════════╗\n");
	printf("║                  PROFESSIONAL EXPERIENCE                         ║\n");
	printf("╚══════════════════════════════════════════════════════════════════╝\n\n");

	while (exp)
	{
		printf("▸ %s\n", exp->position);
		printf("  %s, %s\n", exp->company, exp->location);
		printf("  %s - %s\n\n", exp->start_date, exp->end_date);

		if (exp->responsibilities)
		{
			printf("  Responsibilities:\n");
			print_skill_list(exp->responsibilities);
		}

		if (exp->next)
			printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
		exp = exp->next;
	}
}

void	print_header(t_cv *cv)
{
	if (!cv)
		return ;
	printf("\n");
	printf("████████████████████████████████████████████████████████████████████\n");
	printf("██                                                                ██\n");
	if (cv->name)
		print_centered(cv->name, 64);
	if (cv->title)
		print_centered(cv->title, 64);
	printf("██                                                                ██\n");
	printf("████████████████████████████████████████████████████████████████████\n");
	printf("\n");
	printf("  📍 %s  |  📧 %s  |  📱 %s  |  🔗 %s\n",
		cv->location, cv->email, cv->phone, cv->github);
}

void	print_profile(t_cv *cv)
{
	if (!cv)
		return ;
	printf("╔══════════════════════════════════════════════════════════════════╗\n");
	printf("║                    PROFESSIONAL PROFILE                          ║\n");
	printf("╚══════════════════════════════════════════════════════════════════╝\n\n");
	printf("%s\n", cv->profile);
}

static void	print_menu(void)
{
	printf("\n");
	print_separator();
	printf("  ┌─────────────────────────────────────────┐\n");
	printf("  │           SELECT A SECTION              │\n");
	printf("  ├─────────────────────────────────────────┤\n");
	printf("  │  [1]  Professional profile              │\n");
	printf("  │  [2]  Technical skills                  │\n");
	printf("  │  [3]  Projects                          │\n");
	printf("  │  [4]  Education & qualifications        │\n");
	printf("  │  [5]  Professional experience           │\n");
	printf("  │  [0]  Exit                              │\n");
	printf("  └─────────────────────────────────────────┘\n");
	printf("\n  > ");
}

static void	handle_choice(t_cv *cv, char choice)
{
	printf("\n");
	if (choice == '1')
		print_profile(cv);
	else if (choice == '2')
		print_competencies(cv->competencies);
	else if (choice == '3')
		print_projects(cv->projects);
	else if (choice == '4')
		print_education(cv->education);
	else if (choice == '5')
		print_experience(cv->experience);
	else if (choice != '0')
		printf("  Invalid option. Please try again.\n");
}

void	run_menu(t_cv *cv)
{
	char	buf[2];

	if (!cv)
		return ;
	print_header(cv);
	while (1)
	{
		print_menu();
		if (read(STDIN_FILENO, buf, 1) <= 0)
			break ;
		buf[1] = '\0';
		if (buf[0] == '0')
		{
			printf("\n  /* TODO: hire_talent(this_candidate); */\n\n");
			break ;
		}
		if (buf[0] != '\n')
			handle_choice(cv, buf[0]);
		while (read(STDIN_FILENO, buf, 1) == 1 && buf[0] != '\n')
			;
	}
}
