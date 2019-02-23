[%bs.raw {|require('./IssueRow.css')|}];

let component = ReasonReact.statelessComponent("IssueRow");

let make = (~issue: IssueType.issue, _children) => {
  ...component,
  render: _self =>
    <tr>
      <td className="borderedStyle">
        {ReasonReact.string(string_of_int(issue.id))}
      </td>
      <td className="borderedStyle"> {ReasonReact.string(issue.status)} </td>
      <td className="borderedStyle"> {ReasonReact.string(issue.owner)} </td>
      <td className="borderedStyle"> {ReasonReact.string(issue.created)} </td>
      <td className="borderedStyle">
        {ReasonReact.string(string_of_int(issue.effort))}
      </td>
      <td className="borderedStyle">
        {ReasonReact.string(issue.completedDate)}
      </td>
      <td className="borderedStyle"> {ReasonReact.string(issue.title)} </td>
    </tr>,
};