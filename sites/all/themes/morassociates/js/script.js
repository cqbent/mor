/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - http://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {
	// functions for dynamically setting main and home height based on browser window height
	
	// set search form block element
	var search_form_block = '.block-search-by-page';
	var window_width = 900;
	
	jQuery(document).ready(function(e) {
		resetMainHeight();
		setHomeHeight();
		resetMainWidth();
    });
	jQuery(window).resize(function() {
		resetMainHeight();
		resetHomeHeight();
		resetMainWidth();
	});
	function resetMainHeight() {
		var innerHeight = jQuery(window).height() - 70 - 188 - 70 - 33 - 0 - 0 - 80 - 30;
		//jQuery('.not-front #content .inner').css({minHeight:innerHeight+"px"});
		var xx = jQuery('#content').height();
	}
	var homeContentHeight = 0, homeInnerHeight = 0, subheadHeight = 0, subheadMinHeight = 0;
	
	function setHomeHeight() {
		subheadHeight = jQuery('#subhead').height();
		resetHomeHeight()
	}
	function resetHomeHeight() {
		homeContentHeight = jQuery(window).height() - 120;
		homeContentWidth = jQuery(window).width();
		homeInnerHeight = jQuery('#content .inner').height();
		subheadMinHeight = homeContentHeight - homeInnerHeight;
		if ((subheadMinHeight > subheadHeight) && homeContentWidth > window_width) {
			jQuery('.front #subhead .region-sub-head').css({height:subheadMinHeight+'px'});
			//alert(subheadMinHeight);
		}
		else if (homeContentWidth < window_width) {
			jQuery('.front #subhead .region-sub-head').css({height:'180px'});
		}
	}
	
	// functions for resetting elements based on browser width
	function resetMainWidth() {
		var btn_src = $(search_form_block+' input[type=image]').attr('src');
		var inner_width = jQuery(window).width() - 40;
		if (btn_src) {
			if (jQuery(window).width() < window_width && btn_src.indexOf('magnifying_glass') != -1) {
				btn_src = btn_src.replace('magnifying_glass','button');
				$(search_form_block+' input[type=image]').attr('src',btn_src);
				
			}
			else if (jQuery(window).width() > window_width && btn_src.indexOf('button') != -1) {
				btn_src = btn_src.replace('button','magnifying_glass');
				$(search_form_block+' input[type=image]').attr('src',btn_src);
			}
		}
		if (inner_width < (window_width-40)) {
			$('#main').find('img').each(function() {
				if ($(this).width() >= inner_width) {
					$(this).css('max-width',inner_width);
				}
				else if ($(this).css('max-width') != inner_width) {
					$(this).css('max-width',inner_width);
				}
			});
		}
	}
	
	jQuery(document).ready(function(e) {
		// replace block search title with icon and add trigger
		$(search_form_block+' h2.block-title').html('').toggleClick(
			function() {
				$('#block-system-main-menu').find('.menu').first().css('display','none');
				$(search_form_block+' form').show();
			}, 
			function() { $(search_form_block+' form').hide(); }
		);
		// add trigger to search title link 
 		$('#block-system-main-menu h2').toggleClick(
			function() { 
				$(search_form_block+' form').hide(); 
				$('#block-system-main-menu').find('.menu').first().css('display','block'); 
			}, 
			function() { $('#block-system-main-menu').find('.menu').first().css('display','none'); }
		);
		
			// homepage maxim function
		var hm_current = 1;
		var hm_div = '#block-views-homepage-maxim-block-1';
		var hm_bkimg = $(hm_div+' li.views-row-1 .views-field-field-background-image img').attr('src');
		if (hm_bkimg) {
			var hm_num = $(hm_div+' .hm-list li').length;
			$('body').css({'background-image':'url('+hm_bkimg+')', 'filter': 'progid:DXImageTransform.Microsoft.AlphaImageLoader(src="'+hm_bkimg+'", sizingMethod="scale")'});
		}
		$(hm_div+' .pager-next').click(
			function() {
				//hm_current = hm_current++ > hm_num ? 1 : hm_current++;
				if ((hm_current + 1) > hm_num) { hm_current = 1; }
				else { hm_current++; }
				swap_hm(hm_current);
				//alert(hm_current);
			}
		);
		$(hm_div+' .pager-previous').click(
			function() {
				//hm_current = hm_current-- == 0 ? hm_num : hm_current--;
				if ((hm_current - 1) < 1) { hm_current = hm_num; }
				else { hm_current--; }
				swap_hm(hm_current);
				//alert(hm_current);
			}
		);
		
		function swap_hm(id) {
			$(hm_div+' .hm-list li').hide();
			$(hm_div+' .hm-list li.views-row-'+id).show();
			hm_bkimg = $(hm_div+' li.views-row-'+id+' .views-field-field-background-image img').attr('src');
			$('body').css({'background-image':'url('+hm_bkimg+')', 'filter': 'progid:DXImageTransform.Microsoft.AlphaImageLoader(src="'+hm_bkimg+'", sizingMethod="scale")'});
		}

		

		
		// trigger subnav on parent nav link click
		/*
		$('#block-system-main-menu .menu li.expanded a').toggleClick(
			// hide all menu items; show current menu item
			function() { 
				//$('#block-system-main-menu .menu > li').css('display','none');
				$(this).parent('li').siblings().css('display','none');
				//$(this).css('display','block');
				$(this).parent('li').children('.menu').css('display','block');
				//$(this).find('.menu li').css('display','block');
				alert($(this).text());
			},
			function() {
				$(this).parent('li').siblings().css('display','block');
				$(this).parent('li').children('.menu').css('display','none');
				alert($(this).text());
				//$(this).find('.menu li').css('display','none');
			}
		);
		*/
		
		// display home main content box xx seconds after page loads
		if (jQuery(window).width() > window_width) {
       		$('.front #main').delay(2000).fadeTo('slow',1);
		}
		else {
			$('.front #main').css('opacity',1);
			// remove link on expanded parent items
			//$('#block-system-main-menu .menu').children('li.expanded').children('a').attr('href','#');
			$('#block-system-main-menu .menu').children('li.expanded').children('a').click(function() { return false; });
			// hide all menu items; show current menu item
			$('#block-system-main-menu .menu li.expanded a').click(
				function() { 
					//alert('this');
					if ($(this).parent('li').siblings().hasClass('hide')) {
						$(this).parent('li').siblings().removeClass('hide');
						$(this).parent('li').parent('ul').removeClass('on');
						$(this).parent('li').children('.menu').css('display','none');
					}
					else {
						$(this).parent('li').siblings().addClass('hide');
						$(this).parent('li').children('.menu').css('display','block');
						$(this).parent('li').parent('ul').addClass('on');
					
					}
					
				}
			);
		}
    });
	
	// custom toggle click function now that jquery toggle is deprecated
	$.fn.toggleClick=function(){
		var functions=arguments, iteration=0;
		return this.click(function(){
			functions[iteration].apply(this,arguments);
			iteration = (iteration+1) % functions.length;
		});
	}
	
	
	// extra text for testing...

	
	



})(jQuery, Drupal, this, this.document);
