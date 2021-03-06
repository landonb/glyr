#################################################################
# This file is part of glyr
# + a command-line tool and library to download various sort of music related metadata.
# + Copyright (C) [2011-2016]  [Christopher Pahl]
# + Hosted at: https://github.com/sahib/glyr
#
# glyr is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# glyr is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with glyr. If not, see <http://www.gnu.org/licenses/>.
#################################################################
#!/usr/bin/env python
# encoding: utf-8

from tests.__common__ import *

not_found_options = {
        'get_type': 'similarsongs',
        'artist': 'The band they called Horse',
        'title': 'The album you all know.'
        }

TESTCASES = [{
    # {{{
    'name': 'lastfm',
    'data': [{
        'options': {
            'get_type': 'similarsongs',
            'artist': 'Equilibrium',
            'title': 'Wurzelbert'
            },
        'expect': len_greater_0
        }, {
        'options': {
            'get_type': 'similarsongs',
            'artist': 'In Flames',
            'title': 'Trigger',
            'number': 3
            },
        'expect': lambda r: len(r) == 3
        }, {
        'options': not_found_options,
        'expect': len_equal_0
        }],
    },
    # }}}
]
