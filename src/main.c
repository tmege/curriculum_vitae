#include "cv.h"

static void	populate_competencias(t_cv *cv)
{
	cv->competencias = competencias_init();
	
	// Lenguajes
	skill_add_back(&cv->competencias->lenguajes, skill_new("C"));
	skill_add_back(&cv->competencias->lenguajes, skill_new("Python"));
	skill_add_back(&cv->competencias->lenguajes, skill_new("Bash"));
	
	// Herramientas
	skill_add_back(&cv->competencias->herramientas, skill_new("Git/GitHub"));
	skill_add_back(&cv->competencias->herramientas, skill_new("n8n"));
	skill_add_back(&cv->competencias->herramientas, skill_new("VSCode"));
	skill_add_back(&cv->competencias->herramientas, skill_new("Vim"));
	skill_add_back(&cv->competencias->herramientas, skill_new("Docker"));
	skill_add_back(&cv->competencias->herramientas, skill_new("VirtualBox"));
	
	// Sistemas
	skill_add_back(&cv->competencias->sistemas, skill_new("Linux (Arch)"));
	skill_add_back(&cv->competencias->sistemas, skill_new("Windows"));
	skill_add_back(&cv->competencias->sistemas, skill_new("macOS"));
	
	// Competencias técnicas
	skill_add_back(&cv->competencias->competencias_tecnicas, skill_new("Parsing y procesamiento de texto"));
	skill_add_back(&cv->competencias->competencias_tecnicas, skill_new("Pipes y redirecciones"));
	skill_add_back(&cv->competencias->competencias_tecnicas, skill_new("Gestión de memoria (malloc/free)"));
	skill_add_back(&cv->competencias->competencias_tecnicas, skill_new("Debugging (gdb, valgrind)"));
	skill_add_back(&cv->competencias->competencias_tecnicas, skill_new("Scripts Bash y automatización"));
	skill_add_back(&cv->competencias->competencias_tecnicas, skill_new("Gestión de proyectos"));
	skill_add_back(&cv->competencias->competencias_tecnicas, skill_new("Trabajo en equipo"));
	
	// Idiomas
	skill_add_back(&cv->competencias->idiomas, skill_new("Francés (nativo)"));
	skill_add_back(&cv->competencias->idiomas, skill_new("Inglés (fluido)"));
	skill_add_back(&cv->competencias->idiomas, skill_new("Español (profesional)"));
}

static void	populate_proyectos(t_cv *cv)
{
	t_proyecto	*proyecto;
	
	// Mini-shell
	proyecto = proyecto_new(
		"Mini-shell en C",
		"42 Barcelona",
		"Diseño e implementación de un shell simplificado en C con parsing de comandos, "
		"gestión de pipes, redirecciones I/O y ejecución de comandos externos. "
		"Gestión rigurosa de memoria y manejo de errores."
	);
	skill_add_back(&proyecto->tecnologias, skill_new("C"));
	skill_add_back(&proyecto->tecnologias, skill_new("Makefile"));
	skill_add_back(&proyecto->tecnologias, skill_new("System calls"));
	add_proyecto(cv, proyecto);
	
	// Biblioteca de funciones
	proyecto = proyecto_new(
		"Biblioteca de funciones (libft)",
		"42 Barcelona",
		"Desarrollo de una biblioteca de funciones fundamentales de bajo nivel, "
		"reimplementando funciones estándar de C y estructuras de datos."
	);
	skill_add_back(&proyecto->tecnologias, skill_new("C"));
	skill_add_back(&proyecto->tecnologias, skill_new("Estructuras de datos"));
	skill_add_back(&proyecto->tecnologias, skill_new("Gestión de memoria"));
	add_proyecto(cv, proyecto);
	
	// Administración de sistemas
	proyecto = proyecto_new(
		"Administración de sistemas",
		"Proyecto personal",
		"Configuración y administración de Arch Linux, automatización de tareas "
		"mediante scripts Bash, gestión de servicios y optimización del sistema."
	);
	skill_add_back(&proyecto->tecnologias, skill_new("Arch Linux"));
	skill_add_back(&proyecto->tecnologias, skill_new("Bash"));
	skill_add_back(&proyecto->tecnologias, skill_new("systemd"));
	add_proyecto(cv, proyecto);
	
	// Automatización y LLM
	proyecto = proyecto_new(
		"Automatización con LLM y scraping de datos",
		"Proyectos personales",
		"Creación de un bot para scraping de datos vía API. "
		"Automatización de workflows con n8n y experimentación con modelos de lenguaje (LLM)."
	);
	skill_add_back(&proyecto->tecnologias, skill_new("Python"));
	skill_add_back(&proyecto->tecnologias, skill_new("n8n"));
	skill_add_back(&proyecto->tecnologias, skill_new("APIs REST"));
	add_proyecto(cv, proyecto);
}

static void	populate_formacion(t_cv *cv)
{
	t_formacion	*form;
	
	// 42 Barcelona
	form = formacion_new(
		"Formación en informática",
		"42 Barcelona",
		"España",
		"Marzo 2025",
		"En curso",
		"Metodología basada en proyectos, aprendizaje peer-to-peer y autonomía"
	);
	add_formacion(cv, form);
	
	// CAP Electricista
	form = formacion_new(
		"CAP Electricista",
		"L'École Des Pros",
		"Francia",
		"Diciembre 2021",
		"Junio 2022",
		"Instalación, mantenimiento y cableado eléctrico"
	);
	add_formacion(cv, form);
	
	// Ingeniería de sonido
	form = formacion_new(
		"Ingeniería de sonido y música",
		"L'Institut d'enregistrement du Canada",
		"Canadá",
		"Enero 2018",
		"Enero 2019",
		"Grabación, mezcla, masterización y dominio de software profesional"
	);
	add_formacion(cv, form);
	
	// Biología
	form = formacion_new(
		"Licenciatura en Biología",
		"Universidad de Montreal",
		"Canadá",
		"Septiembre 2014",
		"Diciembre 2017",
		"Análisis científicos, competencias en laboratorio y biología animal"
	);
	add_formacion(cv, form);
}

static void	populate_experiencia(t_cv *cv)
{
	t_experiencia	*exp;
	
	// Studio 22 Barcelona
	exp = experiencia_new(
		"Ingeniero de sonido",
		"Studio 22",
		"Barcelona, España",
		"Marzo 2023",
		"Marzo 2025"
	);
	skill_add_back(&exp->responsabilidades, skill_new("Grabación y mezcla de audio profesional"));
	skill_add_back(&exp->responsabilidades, skill_new("Gestión de proyectos y planificación de sesiones"));
	skill_add_back(&exp->responsabilidades, skill_new("Relación con clientes y comunicación técnica"));
	skill_add_back(&exp->responsabilidades, skill_new("Trabajo en equipo y coordinación de recursos"));
	add_experiencia(cv, exp);
	
	// Studio Niel París
	exp = experiencia_new(
		"Ingeniero de sonido",
		"Studio Niel",
		"París, Francia",
		"Junio 2019",
		"Junio 2022"
	);
	skill_add_back(&exp->responsabilidades, skill_new("Grabación y mezcla de audio"));
	skill_add_back(&exp->responsabilidades, skill_new("Gestión de proyectos"));
	skill_add_back(&exp->responsabilidades, skill_new("Relación con clientes"));
	skill_add_back(&exp->responsabilidades, skill_new("Coordinación de equipos de producción"));
	add_experiencia(cv, exp);
	
	// Zoo de Kuala Lumpur
	exp = experiencia_new(
		"Voluntario en zoología",
		"Zoo de Kuala Lumpur",
		"Malasia",
		"Verano 2016",
		"Verano 2016"
	);
	skill_add_back(&exp->responsabilidades, skill_new("Cuidado y observación de animales"));
	skill_add_back(&exp->responsabilidades, skill_new("Recopilación de datos de comportamiento"));
	skill_add_back(&exp->responsabilidades, skill_new("Trabajo en equipo internacional"));
	add_experiencia(cv, exp);
}

int	main(void)
{
	t_cv	*cv;
	
	cv = cv_init();
	if (!cv)
		return (1);
	
	// Información personal
	cv->nombre = strdup("Timothee Pablo Mege");
	cv->ubicacion = strdup("Barcelona, España");
	cv->email = strdup("timothe.mege@gmail.com");
	cv->telefono = strdup("+34 613 444 715");
	cv->perfil = strdup(
		"Estudiante de informática en 42 Barcelona (metodología basada en proyectos, "
		"autonomía y aprendizaje entre pares). Desarrollo competencias sólidas en C, Bash "
		"y Python a través de proyectos concretos (mini-shell, gestión de sistemas, scripting, "
		"scraping de datos). Con experiencia profesional rica en rigor, análisis y resolución "
		"de problemas (ingeniería de sonido, electricidad, biología), busco un puesto junior "
		"donde pueda poner en práctica mis aptitudes técnicas, contribuir a proyectos innovadores "
		"y seguir progresando en mi camino como desarrollador."
	);
	
	// Poblar secciones
	populate_competencias(cv);
	populate_proyectos(cv);
	populate_formacion(cv);
	populate_experiencia(cv);
	
	// Menu interactivo
	run_menu(cv);
	
	// Liberar memoria
	free_cv(cv);
	
	return (0);
}
