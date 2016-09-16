<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * A QUICK OVERVIEW OF DRUPAL THEMING
 *
 *   The default HTML for all of Drupal's markup is specified by its modules.
 *   For example, the comment.module provides the default HTML markup and CSS
 *   styling that is wrapped around each comment. Fortunately, each piece of
 *   markup can optionally be overridden by the theme.
 *
 *   Drupal deals with each chunk of content using a "theme hook". The raw
 *   content is placed in PHP variables and passed through the theme hook, which
 *   can either be a template file (which you should already be familiary with)
 *   or a theme function. For example, the "comment" theme hook is implemented
 *   with a comment.tpl.php template file, but the "breadcrumb" theme hooks is
 *   implemented with a theme_breadcrumb() theme function. Regardless if the
 *   theme hook uses a template file or theme function, the template or function
 *   does the same kind of work; it takes the PHP variables passed to it and
 *   wraps the raw content with the desired HTML markup.
 *
 *   Most theme hooks are implemented with template files. Theme hooks that use
 *   theme functions do so for performance reasons - theme_field() is faster
 *   than a field.tpl.php - or for legacy reasons - theme_breadcrumb() has "been
 *   that way forever."
 *
 *   The variables used by theme functions or template files come from a handful
 *   of sources:
 *   - the contents of other theme hooks that have already been rendered into
 *     HTML. For example, the HTML from theme_breadcrumb() is put into the
 *     $breadcrumb variable of the page.tpl.php template file.
 *   - raw data provided directly by a module (often pulled from a database)
 *   - a "render element" provided directly by a module. A render element is a
 *     nested PHP array which contains both content and meta data with hints on
 *     how the content should be rendered. If a variable in a template file is a
 *     render element, it needs to be rendered with the render() function and
 *     then printed using:
 *       <?php print render($variable); ?>
 *
 * ABOUT THE TEMPLATE.PHP FILE
 *
 *   The template.php file is one of the most useful files when creating or
 *   modifying Drupal themes. With this file you can do three things:
 *   - Modify any theme hooks variables or add your own variables, using
 *     preprocess or process functions.
 *   - Override any theme function. That is, replace a module's default theme
 *     function with one you write.
 *   - Call hook_*_alter() functions which allow you to alter various parts of
 *     Drupal's internals, including the render elements in forms. The most
 *     useful of which include hook_form_alter(), hook_form_FORM_ID_alter(),
 *     and hook_page_alter(). See api.drupal.org for more information about
 *     _alter functions.
 *
 * OVERRIDING THEME FUNCTIONS
 *
 *   If a theme hook uses a theme function, Drupal will use the default theme
 *   function unless your theme overrides it. To override a theme function, you
 *   have to first find the theme function that generates the output. (The
 *   api.drupal.org website is a good place to find which file contains which
 *   function.) Then you can copy the original function in its entirety and
 *   paste it in this template.php file, changing the prefix from theme_ to
 *   morassociates_. For example:
 *
 *     original, found in modules/field/field.module: theme_field()
 *     theme override, found in template.php: morassociates_field()
 *
 *   where morassociates is the name of your sub-theme. For example, the
 *   zen_classic theme would define a zen_classic_field() function.
 *
 *   Note that base themes can also override theme functions. And those
 *   overrides will be used by sub-themes unless the sub-theme chooses to
 *   override again.
 *
 *   Zen core only overrides one theme function. If you wish to override it, you
 *   should first look at how Zen core implements this function:
 *     theme_breadcrumbs()      in zen/template.php
 *
 *   For more information, please visit the Theme Developer's Guide on
 *   Drupal.org: http://drupal.org/node/173880
 *
 * CREATE OR MODIFY VARIABLES FOR YOUR THEME
 *
 *   Each tpl.php template file has several variables which hold various pieces
 *   of content. You can modify those variables (or add new ones) before they
 *   are used in the template files by using preprocess functions.
 *
 *   This makes THEME_preprocess_HOOK() functions the most powerful functions
 *   available to themers.
 *
 *   It works by having one preprocess function for each template file or its
 *   derivatives (called theme hook suggestions). For example:
 *     THEME_preprocess_page    alters the variables for page.tpl.php
 *     THEME_preprocess_node    alters the variables for node.tpl.php or
 *                              for node--forum.tpl.php
 *     THEME_preprocess_comment alters the variables for comment.tpl.php
 *     THEME_preprocess_block   alters the variables for block.tpl.php
 *
 *   For more information on preprocess functions and theme hook suggestions,
 *   please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/node/223440 and http://drupal.org/node/1089656
 */


/**
 * Override or insert variables into the maintenance page template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("maintenance_page" in this case.)
 */
/* -- Delete this line if you want to use this function
function morassociates_preprocess_maintenance_page(&$variables, $hook) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  morassociates_preprocess_html($variables, $hook);
  morassociates_preprocess_page($variables, $hook);
}
// */

/**
 * Override or insert variables into the html templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */
function morassociates_preprocess_html(&$variables, $hook) {
  //$variables['sample_variable'] = t('Lorem ipsum.');
	$path = drupal_get_path('theme', 'morassociates');
	drupal_add_css('http://fast.fonts.com/jsapi/13d1a4f7-0f26-49f8-be26-077a666af3ee.js',array('type' => 'external'));
	drupal_add_css($path."/css/responsive.css", array('group' => CSS_THEME, 'every_page' => true, 'weight' => 9999));
  drupal_add_js('https://use.fontawesome.com/cc093404c9.js', array('type' => 'external'));
  // The body tag's classes are controlled by the $classes_array variable. To
  // remove a class from $classes_array, use array_diff().
  //$variables['classes_array'] = array_diff($variables['classes_array'], array('class-to-remove'));
}
// */

/**
 * Override or insert variables into the page templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
/* -- Delete this line if you want to use this function
function morassociates_preprocess_page(&$variables, $hook) {
  //$variables['sample_variable'] = t('Lorem ipsum.');
  //$variables['postdate'] = format_date($variables['node']->created, 'minimal');
}
// */

/**
 * Override or insert variables into the node templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
function morassociates_preprocess_node(&$variables, $hook) {
  //$variables['sample_variable'] = t('Lorem ipsum.');

  // Optionally, run node-type-specific preprocess functions, like
  // morassociates_preprocess_node_page() or morassociates_preprocess_node_story().
  $function = __FUNCTION__ . '_' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}
// */

function morassociates_preprocess_node_blog(&$variables, $hook) {
	// alter submitted date display
	$variables['pubdate'] = '<time pubdate datetime="' . format_date($variables['node']->created, 'custom', 'c') . '">' . format_date($variables['node']->created, 'minimal') . '</time>';
	if ($variables['display_submitted']) {
		$variables['submitted'] = t('!pubdate', array('!pubdate' => $variables['pubdate']));
	}
	
	
	// alter links display
	//if (isset($variables['content']['links'])) {
		//
	//}
	//kpr($variables);
}

/**
 * Override or insert variables into the comment templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
function morassociates_preprocess_comment(&$variables, $hook) {
	// alter submitted variable
	$variables['pubdate'] = '<time pubdate datetime="' . format_date($variables['comment']->created, 'custom', 'c') . '">' . format_date($variables['comment']->created, 'custom', 'F d, Y') . '</time>';
	$variables['pubtime'] = format_date($variables['comment']->created, 'custom', 'g:i a');
	$variables['submitted'] = t('<span class="commentdate">!commentdate</span><span class="commenttime">!commenttime</span>', array('!commentdate' => $variables['pubdate'], '!commenttime' => $variables['pubtime']));
	// alter author variable
	$variables['by_author'] = t('By: !author',array('!author' => strip_tags($variables['author'])));

}
// */

/**
 * Override or insert variables into the region templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("region" in this case.)
 */
/* -- Delete this line if you want to use this function
function morassociates_preprocess_region(&$variables, $hook) {
  // Don't use Zen's region--sidebar.tpl.php template for sidebars.
  //if (strpos($variables['region'], 'sidebar_') === 0) {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('region__sidebar'));
  //}
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
function morassociates_preprocess_block(&$variables, $hook) {
  // Add a count to all the blocks in the region.
  // $variables['classes_array'][] = 'count-' . $variables['block_id'];

  // By default, Zen will use the block--no-wrapper.tpl.php for the main
  // content. This optional bit of code undoes that:
  //if ($variables['block_html_id'] == 'block-system-main') {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('block__no_wrapper'));
  //}
}
// */

function morassociates_form_alter(&$form, &$form_state, $form_id) {
	if ($form_id == 'search_block_form') {
		$form['search_block_form']['#title'] = t('Search'); // Change the text on the label element
		$form['search_block_form']['#title_display'] = 'invisible'; // Toggle label visibilty
		//$imgbutton = ($form_id == 'search_block_form') ? 'magnifying_glass.png' : 'magnifying_glass_gray.png';
		$form['actions']['submit'] = array('#type' => 'image_button', '#src' => base_path() . path_to_theme() . '/images/magnifying_glass.png');
		//$form['actions']['search'] = array('#type' => 'image_button', '#src' => base_path() . path_to_theme() . '/images/'.$imgbutton);
	}
	else if ($form_id == 'views_exposed_form' && $form['#id'] == 'views-exposed-form-insight-page') {
		$form['submit'] = array('#type' => 'image_button', '#src' => base_path() . path_to_theme() . '/images/magnifying_glass_gray.png');
		
	}
	else if ($form_id == 'search_by_page_form') {
		//$form['search_by_page_form']['#title'] = t('Search'); // Change the text on the label element
		//$form['search_by_page_form']['#title_display'] = 'invisible'; // Toggle label visibilty
		$form['submit'] = array('#type' => 'image_button', '#src' => base_path() . path_to_theme() . '/images/magnifying_glass.png');
	}

}	

function displayAuthorPostInfo($author,$comments) {
		$author_name = strip_tags($author); 
		$author_url = strtolower(preg_replace('/\s+/', '-', $author_name));
		return t('By: <a href="/insight/!author_url">!author_name</a> <br />!comment_count Comments',array('!author_url' => $author_url, '!author_name' => $author_name, '!comment_count' => $comments));
}

/*
function morassociates_preprocess_menu_tree(&$variables) {
  //$variables['tree'] = $variables['tree']['#children'];
  //dsm(&$variables);
}
*/

function morassociates_menu_tree($variables) {
  return '<ul class="menu">' . $variables['tree'] . '</ul>';
}

function morassociates_menu_link(array $variables) {
	$element = $variables['element'];
	$sub_menu = '';
	$element['#attributes']['class'][] = 'depth-' . $element['#original_link']['depth'];
	if ($element['#below']) {
		$sub_menu = drupal_render($element['#below']);
	}
	$output = l($element['#title'], $element['#href'], $element['#localized_options']);
	return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}
